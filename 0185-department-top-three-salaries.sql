# Write your MySQL query statement below
SELECT d.Name AS Department,
    e.Name AS Employee,
    e.Salary AS Salary
FROM Employee e , Department d 
WHERE (
    e.DepartmentId=d.Id AND 
    (SELECT COUNT(DISTINCT e2.Salary) FROM Employee e2 
        WHERE (e2.Salary > e.Salary) AND e2.DepartmentId=e.DepartmentId) < 3 
) 

