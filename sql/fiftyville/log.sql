-- Keep a log of any SQL queries you execute as you solve the mystery.
-- O roubo aconteceu em 28 de julho de 2023 na rua de Humphrey Street

-- Obtendo relatório do crime
SELECT * FROM crime_scene_reports
WHERE day = 28
AND month = 7
AND year = 2023
AND street = 'Humphrey Street';

-- O roubo aconteceu as 10:15 da manhã na padaria da rua Humphrey Street. 3 testemunhas

SELECT * FROM bakery_security_logs
WHERE year = 2023
AND month = 7
AND day = 28
AND hour <= 10

-- 4 pessoas deram entrada e estavam na hora do roubo
-- 4328GD8 - Entrada as 9:14
-- 5P2BI95 - Entrada as 9:15
-- R3G7486 - Entrada as 10:08
-- 13FNH73 - Entrada as 10:14
-- Mas muitas pessoas deram entrada antes do roubo

-- Entrevistas pelas 3 pessoas que estavam presentes na hora do roubo
SELECT * FROM interviews
WHERE day = 28
AND month = 7
AND year = 2023;

-- Ruth -> Em algum momento de dez minutos do roubo, vi o ladrão entrar em um carro no estacionamento da padaria e me afastar. Se você tiver imagens de segurança no estacionamento da padaria, pode querer procurar carros que deixassem o estacionamento nesse período.

-- Eugene -> Não conheço o nome do ladrão, mas foi alguém que eu reconheci. No início desta manhã, antes de chegar à padaria de Emma, ​​eu estava andando pelo caixa eletrônico na Leggett Street e vi o ladrão lá retirando algum dinheiro.

-- Raymond -> Quando o ladrão estava deixando a padaria, eles ligaram para alguém que conversou com eles por menos de um minuto. Na ligação, ouvi o ladrão dizer que eles estavam planejando tirar o voo mais cedo de Fiftyville amanhã. O ladrão então pediu à pessoa do outro lado do telefone para comprar a passagem de voo. |

-- Resumindo, antes do roubo o ladrão o ladrão tirou um dinheiro no caixa eletrônico da rua Leggett Street, após o roubo, ao deixar a padaria ele ligou para alguém e conversou por menos de 1 minito pedindo para comprar passagens aereas, logo após, 10 min após o roubo ele entrou no carro que estava no estacionamento da padaria, mandou o parceiro comprar a passagem para o outro dia mais cedo

-- Pessoas que sacaram o dinheiro no dia do roubo, citado na entrevista de Eugene
SELECT * FROM atm_transactions
WHERE year = 2023
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- 8 Resultados com número da conta bancaria

-- Acessando conta bancária e recebendo id da pessoa e o ano de criação da conta
SELECT * FROM bank_accounts JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2023
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- identificando o nome das pessoas que são donos dessas contas
SELECT name, phone_number, passport_number, license_plate FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2023
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- 8 resultados possiveis
-- numero de telefone retornado e numero do passaporte e o licence plate usado para entrar na padaria
SELECT name FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = 2023
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw'
AND bakery_security_logs.year = 2023
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour <= 10;

-- Estavam na hora do roubo e sacaram dinheiro no banco antes
--           Telefone:    | Passaporte    | License_plate |  Numero da conta do banco:
-- Bruce,  (367) 555-5533 | 5773159633    | 94KL13X       | 49610011
-- Diana,  (770) 555-1861 | 3592750733    | 322W7JE       | 26013199
-- Iman,   (829) 555-5269 | 7049073643    | L93JTIZ       | 25506511
-- Luca,   (389) 555-5198 | 8496433585    | 4328GD8       | 28500762
-- Taylor, (286) 555-6063 | 1988161715    | 1106N58       | 76054385


-- Ligações feitas no dia do roubo que duraram menos de 1 min, Raymond citou
SELECT * FROM phone_calls
WHERE year = 2023
AND month = 7
AND day = 28
AND duration < 60
AND caller = '(367) 555-5533';

-- Bruce ligou para - [ROBIN] (375) 555-8161 PASSAPORTE: NULL.
-- Diana ligou para 1 pessoa - [PHILIP] (725) 555-3243 PASSAPORTE: 3391710505.
-- Iman não ligou para ninguém
-- Luca não ligou para ninguém
-- Taylor ligou para - [JAMES] (676) 555-6554 PASSAPORTE: 2438825627.

SELECT * FROM people
WHERE phone_number = '(375) 555-8161';

-- Bruce, Diana e Taylor

-- Voos que aconteceram apos o dia do roubo, mais cedo
-- Voos que sairam de fiftyville no dia seguinte do roubo pela manhã
SELECT * FROM airports JOIN flights ON airports.id = flights.origin_airport_id
WHERE day = 29
AND month = 7
AND year = 2023
AND city = 'Fiftyville'
ORDER BY hour;

-- id (36, 43, 23, 53, 18) por ordem
-- O ladrão pegou algum desses voos

-- Lista de passageiros de cada voo
SELECT * FROM passengers
WHERE passport_number = 5773159633

-- Bruce Pegou o voo 36
-- Diana estava no voo 18, mas como a ligação pediu para o voo ser mais cedo, muito dificil ser esse
-- Taylor Pegou o voo 36

SELECT * FROM flights
WHERE id = 36
AND day = 29
AND month = 7
AND year = 2023;

-- O voo do id 36 foi do aeroporto 8 para o aeroporto 4

SELECT * FROM airports
WHERE id = 8;

-- Aeroporto 8 é fiftyville
SELECT * FROM airports
WHERE id = 4;

-- Aeroporto 4 é New York City

SELECT * FROM passengers
JOIN flights ON flights.id = passengers.flight_id
WHERE flights.id = 36;

-- Passageiros do voo 36 com destino a nova york

SELECT * FROM passengers
JOIN flights ON flights.id = passengers.flight_id
WHERE flights.id = 36
AND passport_number = 1988161715;

-- Bruce estava no acento 4A desse voo
-- Taylor estava no acento 6D desse voo

-- Mas Bruce cumpre com todos os requisitos do ladrão

-- =======================================================================================================
-- O ladrão foi BRUCE
-- Seu cúmplice foi ROBIN
-- Eles foram para NEW YORK CITY
