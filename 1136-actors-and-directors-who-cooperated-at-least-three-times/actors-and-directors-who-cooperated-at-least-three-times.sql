# Write your MySQL query statement below
SELECT actor_id, director_id FROM
(SELECT actor_id, director_id, COUNT(*) AS counts
FROM ActorDirector GROUP BY actor_id, director_id) AS t
WHERE t.counts >= 3;