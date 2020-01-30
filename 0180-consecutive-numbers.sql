# Write your MySQL query statement below
select distinct l1.Num as ConsecutiveNums from 
    Logs l1 left join Logs l2 on l1.Id + 1 = l2.Id 
    left join Logs l3 on l2.Id + 1 = l3.Id 
    where l1.Num = l2.Num and l2.Num = l3.Num
