#lang racket

(define (sumMinFixedPoints l f)
  (apply +
         (map (lambda (el) (foldl min (car el) el))
              (map (lambda (y) (filter (lambda (z) (= (f z) z)) y)) l))))

; some function which has 2 as a fixed point
(define (f x)
  (+ (- (* x x) (* 3 x)) 4))



(define (smfp numbers functions)
  (apply + 
  (map (lambda (l) (foldl min (if (null? l) 0 (car l)) l))
       (map (lambda (f) (filter (lambda (n) (= n (f n)))
                           numbers))
       functions))))



  
