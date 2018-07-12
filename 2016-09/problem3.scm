(define (filterByElement elem m)
  (filter (lambda (l) (member elem l)) m)
  )