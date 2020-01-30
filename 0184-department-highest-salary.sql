# Write your MySQL query statement below
SELECT Department.Name AS Department, RESULT.Employee AS Employee, RESULT.Salary AS Salary FROM
    (SELECT DepartmentMax.DepartmentId AS DepartmentId, e.Name AS Employee,
     e.Salary AS Salary, DepartmentMax.maxSalary AS maxSalary FROM Employee e RIGHT JOIN 
    (SELECT DepartmentId, max(Salary) as maxSalary 
         FROM Employee GROUP BY DepartmentId) as DepartmentMax 
     ON e.DepartmentId = DepartmentMax.DepartmentId) AS RESULT
         LEFT JOIN Department ON RESULT.DepartmentId = Department.Id WHERE 
         Department.Name IS NOT NULL AND RESULT.Salary=RESULT.maxSalary
