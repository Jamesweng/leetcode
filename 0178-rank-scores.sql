# Write your MySQL query statement below

SELECT x.Score as Score, y. n as Rank
    FROM
    Scores x LEFT JOIN 
    (SELECT Score,
      @n := @n + 1 n
      FROM
      (SELECT DISTINCT Score FROM Scores ORDER BY Score DESC) a, (SELECT @n := 0) b) y
      on x.Score = y.Score
    ORDER BY Score DESC

