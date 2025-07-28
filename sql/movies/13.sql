-- Seleciona os nomes únicos das pessoas
SELECT DISTINCT name
FROM people
-- Onde o ID da pessoa está entre os IDs das pessoas que atuaram
-- em filmes em que Kevin Bacon também atuou
WHERE id IN (

    -- Subconsulta que retorna os IDs das pessoas que atuaram
    -- em qualquer filme onde Kevin Bacon (nascido em 1958) atuou
    SELECT person_id
    FROM stars
    WHERE movie_id IN (

        -- Subconsulta que retorna os IDs dos filmes onde
        -- Kevin Bacon (1958) atuou
        SELECT movie_id
        FROM stars
        WHERE person_id = (

            -- Subconsulta que retorna o ID do Kevin Bacon nascido em 1958
            SELECT id
            FROM people
            WHERE name = 'Kevin Bacon' AND birth = 1958
        )
    )
)

-- E o ID da pessoa não é o do próprio Kevin Bacon
AND id != (
    SELECT id
    FROM people
    WHERE name = 'Kevin Bacon' AND birth = 1958
);

-- Três níveis de subqueries para:
-- Obter o ID do Kevin Bacon.
-- Obter os filmes em que ele atuou.
-- Obter as pessoas que atuaram nesses filmes.
