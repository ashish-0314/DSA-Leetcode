# Write your MySQL query statement below
select e.name , b.bonus from Employee e left join Bonus b on e.empId = b.empId where b.empId is NULL or b.bonus <1000