-- 코드를 입력하세요
SELECT 
      A.ANIMAL_ID
    , a.ANIMAL_TYPE
    , a.NAME
  from animal_ins a
  join animal_outs b on a.animal_id = b.animal_id
  where a.sex_upon_intake like 'Intact%'
  and (b.sex_upon_outcome like 'Neutered%' or b.sex_upon_outcome like 'Spayed%');