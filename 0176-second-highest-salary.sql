# Write your MySQL query statement below
select max(Salary) as SecondHighestSalary from Employee as a,
    (select max(Salary) as maxSalary from Employee) as b
    where a.Salary != b.maxSalary
