# Write your MySQL query statement below
select Email from 
    (select Email, count(*) as num from Person group by Email) a where
        num > 1
    
