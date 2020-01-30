# Write your MySQL query statement below
select a.Id from Weather a left join Weather b on
   datediff(a.RecordDate,b.RecordDate)=1 where b.Temperature is not null and a.Temperature > b.Temperature
