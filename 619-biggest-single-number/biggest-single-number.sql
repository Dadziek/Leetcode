# Write your MySQL query statement below
SELECT MAX(num) AS num FROM 
(SELECT num, COUNT(*) AS counts FROM MyNumbers GROUP BY num)
AS t WHERE t.counts = 1;