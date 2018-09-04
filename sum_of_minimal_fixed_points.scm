(define (sumMinFixedPoints l f)
  (apply +
 (map (lambda (el) (foldl min 1000 el))
 (map (lambda (y) (filter (lambda (z) (= (f z) z)) y)) l))))

