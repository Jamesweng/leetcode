
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT Salary FROM 
          (SELECT DISTINCT Salary FROM Employee) y
      ORDER BY Salary DESC LIMIT 1 OFFSET N

  );
END

/*
      SELECT Salary FROM 
          (SELECT x.Salary AS Salary, 1 + (SELECT count(1) FROM 
                                           (SELECT DISTINCT Salary FROM Employee) y WHERE y.Salary > x.Salary) AS Rank FROM 
              Employee x) a WHERE Rank = N LIMIT 1
*/
