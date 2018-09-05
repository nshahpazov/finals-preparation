#lang racket

(define (without x lst)
  (cond
    ((null? lst) '())
    ((= x (car lst))(remove x (cdr lst)))
    (else (cons (car lst) (remove x (cdr lst))))))
  
(define (permutations l)
  (cond
    ((= (length l) 1) (list l))
    (else (apply append
                 (map (lambda (x) (map (lambda (y) (cons x y))
                                       (permutations (without x l))))
                      l)))))