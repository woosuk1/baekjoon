-- 코드를 작성해주세요
select
         count(id) as FISH_COUNT
       , extract(month from time) as MONTH
    from fish_info
    group by MONTH
    having count(id) > 0
    order by MONTH;