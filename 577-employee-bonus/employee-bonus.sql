select e.name ,b.bonus from employee e 
left join  bonus b on e.empid = b.empid
where b.bonus is NULL OR b.bonus < 1000