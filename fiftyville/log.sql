-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get the description of the crime scene
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
select description from crime_scene_reports
where street = "Humphrey Street"
and day = 28 and month = 7;

-- Finds the interviews related to the bakery
select transcript from interviews
where transcript like "%bakery%";

-- Get the license plates that exited the bakery within 10 min of the theft
select license_plate from bakery_security_logs
where day = 28 and month = 7
and hour = 10 and minute >= 15 and minute <= 25
and activity = "exit";

-- Get the transactions from the atm at leggett street
select account_number from atm_transactions
where day = 28 and month = 7
and transaction_type = "withdraw"
and atm_location = "Leggett Street";

-- Get the flight the thieves took
select * from flights
join airports on airports.id = flights.origin_airport_id
where day = 29 and month = 7
and city = "Fiftyville"
order by hour;

select * from flights


select * from flights
where day = 28 and month = 7
order by hour;

select name from people
where passport_number in (
select passport_number from passengers
join flights on flights.id = passengers.flight_id
where flight_id = 36);
select passport_number from passengers
join flights on flights.id = passengers.flight_id
where flight_id = 36;

select name from people
join bank_accounts on bank_accounts.person_id = people.id
where license_plate in (select license_plate from bakery_security_logs
where day = 28 and month = 7
and hour = 10 and minute >= 15 and minute <= 25
and activity = "exit")
and account_number in (select account_number from atm_transactions
where day = 28 and month = 7
and transaction_type = "withdraw"
and atm_location = "Leggett Street")
and passport_number in (
select passport_number from passengers
join flights on flights.id = passengers.flight_id
where flight_id = 36);


select passport_number from passengers
where flight_id = 6;

select id from airports
join flights on flights.

-- Get the destination of the flight
select city from airports
where id = 4;

-- Get passport numbers of everybody on the flight
select passport_number from passengers
join flights on flights.id = passengers.flight_id
where flights.id = 4;

-- Get the number of every phone call passed on July 28 that laster less than a minute
select caller from phone_calls
where day = 28 and month = 7
and duration < 60;

select * from people
where license_plate in (select license_plate from bakery_security_logs
where day = 28 and month = 7
and hour = 10 and minute >= 15 and minute <= 30
and activity = "exit")
and phone_number in (select caller from phone_calls
where day = 29 and month = 7
and duration < 60)
and passport_number in (select passport_number from passengers
where flight_id in (select id from flights
where origin_airport_id in (select id from airports
where city = "Fiftyville")));



select * from flights
join passengers on passengers.flight_id = flights.id
where passport_number = 5773159633;

select name from people
join bank_accounts on bank_accounts.person_id = people.id
where account_number in (select account_number from atm_transactions
where day = 28 and month = 7
and transaction_type = "withdraw"
and atm_location = "Leggett Street");

select person_id from bank_accounts
where account_number in (select account_number from atm_transactions
where day = 28 and month = 7
and transaction_type = "withdraw"
and atm_location = "Leggett Street");

select * from people
where phone_number = (select receiver from phone_calls
where caller = "(367) 555-5533");

select passport_number from passengers
where flight_id = 36;

select name from people
where phone_number = (
select receiver from phone_calls
where caller = "(389) 555-5198");

select name from people
where phone_number in
(select receiver from phone_calls
where caller = "(367) 555-5533"
and day = 28 and month = 7
and duration <= 60);