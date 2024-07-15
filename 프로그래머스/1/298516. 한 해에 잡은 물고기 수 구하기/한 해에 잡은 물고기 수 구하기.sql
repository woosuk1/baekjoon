-- 코드를 작성해주세요
select
         count(id) as FISH_COUNT
    from fish_info
    where extract(year from time) = 2021
    group by extract(year from time);
