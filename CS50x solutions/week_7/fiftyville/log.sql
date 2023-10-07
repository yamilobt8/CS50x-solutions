-- Keep a log of any SQL queries you execute as you solve the mystery.
select description from crime_scene_reports where day = 28 and month = 7 and year = 2020 and street = "Chamberlin Street"
select transcript from interviews where day = 28 and month = 7 and year = 2020 and transcript like "%courthouse%
select activity from people join courthouse_security_logs on people.license_plate = courthouse_security_logs.license_plate where day = 28 and month = 7 and year = 2020 and hour = 10 and minute >= 15 and minute < 25 and activity = "exit"
select distinct name from people join bank_accounts on people.id = bank_accounts.person_id join atm_transactions on bank_accounts.account_number = atm_transactions.account_number where day = 28 and month = 7 and year = 2020 and transaction_type = "withdraw" and atm_location = "Fifer Street"
select name from people join passengers on people.passport_number = passengers.passport_number where fight_id = (select id from flights where day = 29 and month = 7 and year = 2020 order by hour, minute limit 1) intersect
select distinct name from people join bank_accounts on people.id = bank_accounts.person_id join atm_transactions on bank_accounts_number = atm_transactions.account_number where day = 28 and month = 7 and year = 2020 and transaction_type =  "withdraw" and atm_location = "Fifer Street" intersect
select name from people join phone_calls on people.phone_number = phone_calls.caller where day = 28 and month = 7 and year = 2020 and duration < 60 intersect
select name from people join courthouse_security_logs on people.license_plate = courthouse_security_logs.license_plate where day = 28 and month = 7 and year = 2020 and hour = 10 and minute >= 15 and minute < 25 and activity = "exit"
select city from airports where id = (select destination_airport_id from flights where day = 29 and month = 7 and year = 2020 order by hour, minute limit 1)
select name from people join  phone_calls on people.phone_number = phone_calls.receiver where day = 28 and month = 7 and year = 2020 and duration < 60 and caller = (select phone_number from people where name = "Ernest")

