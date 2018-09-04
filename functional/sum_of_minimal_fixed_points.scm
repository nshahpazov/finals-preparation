#lang racket

(define (sumMinFixedPoints l f)
  (apply +
 (map (lambda (el) (foldl min (car el) el))
 (map (lambda (y) (filter (lambda (z) (= (f z) z)) y)) l))))

