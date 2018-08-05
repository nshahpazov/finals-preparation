----------------------
select ac.name, si.movietitle, m.studioname, m.year
from moviestar ac inner join starsin si
on ac.name = si.starname
inner join movie m on si.movietitle = m.title
where m.studioname like '%mgm%' and m.year<='1995';


--------------------------------------
-- query where the length is greater than the length of star wars

select * from movie m where m.length > (select top 1 length from movie where title like 'star wars');

-- Напишете заявка, която извежда имената на актрисите, които са също и
-- продуценти с нетна стойност по-голяма от 10 милиона
select ms.name from moviestar ms where ms.gender like 'F' intersect select ex.name from MOVIEEXEC ex;

-- Напишете заявка, която извежда имената на тези актьори (мъже и жени), които
-- не са продуценти.
select ms.name from moviestar ms except select ex.name from MOVIEEXEC ex;

-- Напишете заявка, която извежда имената на всички филми с дължина по-голяма
-- от дължината на филма ‘Gone With the Wind’
select * from movie where length >= (select top  1 length from movie where title like '%gone with the wind%');

-- Напишете заявка, която извежда производителите на персонални компютри с
-- честота поне 100.

select x.maker from product x where x.model in (select p.model from pc p where p.speed > 100);

-- Напишете заявка, която извежда лаптопите, чиято честота е по-ниска от
-- честотата на който и да е персонален компютър.

select lap.* from laptop lap where lap.speed > any (select p.speed from pc p);

-- Напишете заявка, която извежда модела на продукта (PC, лап топ или принтер) с
-- най-висока цена.
-- честотата на който и да е персонален компютър.

select top 1 t.model
from (select l.model, l.price
      from laptop l
      union select p.model, p.price from pc p
      union select pr.model, pr.price from printer pr
) t order by t.price desc;

-- Напишете заявка, която извежда производителите на тези персонални компютри
-- с най-малко RAM памет, които имат най-бързи процесори.

select * from pc p
where p.ram = (select top 1 ram from pc p2 order by p2.ram asc) order by speed desc;

-- Напишете заявка, която за всеки филм, по-дълъг от 120 минути, извежда
-- заглавие, година, име и адрес на студио.

select m.title, m.year, s.name, s.address
from movie m left join studio s
on m.studioname = s.name where m.length > 120;

-- Напишете заявка, която извежда името на студиото и имената на актьорите,
-- участвали във филми, произведени от това студио, подредени по име на студио

select st.name, si.starname
from studio st
full outer join movie m on st.name = m.studioname
full outer join starsin si on m.title = si.movietitle;

-- Напишете заявка, която извежда имената на продуцентите на филмите, в които е
-- играл Harrison Ford.

select me.name, m.title, si.starname from movieexec me
inner join movie m on m.[PRODUCERC#] = me.[CERT#]
inner join starsin si on m.title = si.movietitle
where si.starname like '%ford%';

-- Напишете заявка, която извежда производител, модел и тип на продукт за тези
-- производители, за които съответния продукт не се продава (няма го в таблиците
-- PC, лаптоп или принтер).
select p.*
from product p
left join pc p2 on p.model = p2.model
left join laptop l on p.model = l.model
left join printer pr on p.model = pr.model
where p2.code is null and l.code is null and pr.code is null;

-- За всяка страна изведете имената на корабите, които никога не са участвали в
-- битка.

select * from classes cl
left join ships sh on cl.class = sh.class
left join outcomes o on sh.name = o.ship
where o.battle is null;

