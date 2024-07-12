-- 코드를 작성해주세요

select
         extract(year from YM) as YEAR
       , round(avg(pm_val1), 2) as PM10
       , round(avg(pm_val2), 2) as 'PM2.5'
    from air_pollution
    WHERE location2 = '수원'
    group by YEAR
    ORDER BY YEAR;