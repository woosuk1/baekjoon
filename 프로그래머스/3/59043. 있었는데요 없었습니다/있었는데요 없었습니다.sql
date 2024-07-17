-- 코드를 입력하세요
# select
#          a.datetime
#        , b.datetime
#     from animal_ins a
#     join animal_outs b 
#     on a.animal_id = b.animal_id
#     where timediff(a.datetime, b.datetime) < 0; -- a는 보호시작일, b는 입양일

    

SELECT
         a.animal_id as ANIMAL_ID
       , a.name AS NAME
    from animal_ins a
    join animal_outs b 
    on a.animal_id = b.animal_id
    where a.datetime > b.datetime -- a는 보호시작일, b는 입양일
    order by a.datetime;