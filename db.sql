DROP TABLE IF EXISTS users CASCADE;
DROP TABLE IF EXISTS characters CASCADE;
DROP TABLE IF EXISTS items CASCADE;
DROP TABLE IF EXISTS inventories CASCADE;
DROP TABLE IF EXISTS equipments CASCADE;
DROP TABLE IF EXISTS monsters CASCADE;
DROP TABLE IF EXISTS guilds CASCADE;
DROP TYPE IF EXISTS CATEGORY;
DROP FUNCTION IF EXISTS update_character;
DROP TRIGGER IF EXISTS character_trigger ON characters;
CREATE TABLE users (
    id INTEGER PRIMARY KEY CHECK (id > 0),
    alias VARCHAR NOT NULL UNIQUE CHECK (alias <> ''),
    password VARCHAR NOT NULL CHECK (password <> ''),
    secret VARCHAR NOT NULL CHECK (LENGTH(secret) = 10)
);
CREATE TABLE characters (
    id INTEGER PRIMARY KEY CHECK (id > 0),
    name VARCHAR NOT NULL UNIQUE CHECK (name <> ''),
    health BIGINT NOT NULL CHECK (health >= 0),
    experience BIGINT NOT NULL CHECK (experience >= 0),
    gold BIGINT NOT NULL CHECK (gold >= 0),
    guild_id INTEGER,
    updated_at DATE NOT NULL
);
CREATE TYPE CATEGORY AS ENUM (
    'helmet', 
    'platebody', 
    'platelegs',
    'boots',
    'sword',
    'shield'
);
CREATE TABLE items (
    id INTEGER PRIMARY KEY CHECK (id > 0),
    name VARCHAR NOT NULL UNIQUE CHECK (name <> ''),
    level INTEGER NOT NULL CHECK (level >= 0),
    attack INTEGER NOT NULL CHECK (attack >= 0),
    defense INTEGER NOT NULL CHECK (defense >= 0),
    category CATEGORY NOT NULL,
    buy_price BIGINT NOT NULL CHECK (buy_price >= 0),
    sell_price BIGINT NOT NULL CHECK (sell_price >= 0)
);
CREATE TABLE inventories (
    character_id INTEGER PRIMARY KEY REFERENCES characters(id),
    size INTEGER NOT NULL CHECK (size > 0),
    items INTEGER[] NOT NULL CHECK (array_length(items, 1) <= size)
);
CREATE TABLE equipments (
    character_id INTEGER PRIMARY KEY REFERENCES characters(id),
    helmet_id INTEGER REFERENCES items(id),
    platebody_id INTEGER REFERENCES items(id),
    platelegs_id INTEGER REFERENCES items(id),
    boots_id INTEGER REFERENCES items(id),
    sword_id INTEGER REFERENCES items(id),
    shield_id INTEGER REFERENCES items(id)
);
CREATE TABLE monsters (
    id INTEGER PRIMARY KEY CHECK (id > 0),
    name VARCHAR NOT NULL UNIQUE CHECK (name <> ''),
    level INTEGER NOT NULL CHECK (level >= 0),
    health BIGINT NOT NULL CHECK (health >= 0),
    attack BIGINT NOT NULL CHECK (attack >= 0),
    defense BIGINT NOT NULL CHECK (defense >= 0),
    gold INTEGER NOT NULL CHECK (gold >= 0),
    experience BIGINT NOT NULL CHECK (experience >= 0)
);
CREATE TABLE guilds (
    id INTEGER PRIMARY KEY CHECK (id > 0),
    name VARCHAR NOT NULL UNIQUE CHECK (name <> ''),
    level_required INTEGER CHECK (level_required >= 0),
    leader_id INTEGER REFERENCES characters(id)
);
ALTER TABLE characters 
    ADD CONSTRAINT fk_characters_guilds 
        FOREIGN KEY (guild_id) REFERENCES guilds(id);
CREATE FUNCTION update_character() RETURNS trigger AS $$
    BEGIN
        NEW.updated_at := NOW();
        RETURN NEW;
    END;
$$ LANGUAGE plpgsql;
CREATE TRIGGER update_character_trigger AFTER UPDATE ON characters
    FOR EACH ROW EXECUTE FUNCTION update_character();
DROP ROLE IF EXISTS registrar;
DROP ROLE IF EXISTS authorizer;
DROP ROLE IF EXISTS character_creator;
DROP ROLE IF EXISTS character_manager;
DROP ROLE IF EXISTS inventory_manager;
DROP ROLE IF EXISTS equipment_manager;
DROP ROLE IF EXISTS guild_creator;
DROP ROLE IF EXISTS guild_manager;
CREATE ROLE registrar;
ALTER ROLE registrar WITH LOGIN;
GRANT INSERT ON users TO registrar;
GRANT SELECT ON users TO registrar;
CREATE ROLE authorizer;
ALTER ROLE authorizer WITH LOGIN;
GRANT SELECT ON users TO authorizer;
CREATE ROLE character_creator;
ALTER ROLE character_creator WITH LOGIN;
GRANT INSERT ON characters TO character_creator;
GRANT SELECT ON characters TO character_creator;
GRANT INSERT ON inventories TO character_creator;
GRANT INSERT ON equipments TO character_creator;
CREATE ROLE character_manager;
ALTER ROLE character_manager WITH LOGIN;
GRANT UPDATE ON characters TO character_manager;
GRANT SELECT ON characters TO character_manager;
CREATE ROLE inventory_manager;
ALTER ROLE inventory_manager WITH LOGIN;
GRANT UPDATE ON inventories TO inventory_manager;
GRANT SELECT ON inventories TO inventory_manager;
CREATE ROLE equipment_manager;
ALTER ROLE equipment_manager WITH LOGIN;
GRANT UPDATE ON equipments TO equipment_manager;
GRANT SELECT ON equipments TO equipment_manager;
CREATE ROLE guild_creator;
ALTER ROLE guild_creator WITH LOGIN;
GRANT INSERT ON guilds TO guild_creator;
GRANT SELECT ON guilds TO guild_creator;
CREATE ROLE guild_manager;
ALTER ROLE guild_manager WITH LOGIN;
GRANT UPDATE ON guilds TO guild_manager;
GRANT SELECT ON guilds TO guild_manager;

INSERT INTO monsters (id, name, level, health, attack, defense, gold, experience) VALUES 
(1, 'Крыса', 1, 25, 8, 3, 100, 100),
(2, 'Паук', 3, 40, 11, 5, 200, 200),
(3, 'Скелет', 5, 50, 14, 8, 300, 400),
(4, 'Зомби', 7, 65, 18, 10, 400, 400);

INSERT INTO items (id, name, level, attack, defense, category, buy_price, sell_price) VALUES
(1, 'Бронзовый шлем', 1, 0, 5, 'helmet', 100, 50),
(2, 'Бронзовый нагрудник', 1, 0, 5, 'platebody', 100, 50),
(3, 'Бронзовые поножи', 1, 0, 5, 'platelegs', 100, 50),
(4, 'Бронзовые ботинки', 1, 0, 5, 'boots', 100, 50),
(5, 'Бронзовый меч', 1, 5, 0, 'sword', 100, 50),
(6, 'Бронзовый щит', 1, 0, 5, 'shield', 100, 50),
(7, 'Железный шлем', 5, 0, 10, 'helmet', 500, 250),
(8, 'Железный нагрудник', 5, 0, 10, 'platebody', 500, 250),
(9, 'Железные поножи', 5, 0, 10, 'platelegs', 500, 250),
(10, 'Железные ботинки', 5, 0, 10, 'boots', 500, 250),
(11, 'Железный меч', 5, 10, 0, 'sword', 500, 250),
(12, 'Железный щит', 5, 0, 10, 'shield', 500, 250);


INSERT INTO users (id, alias, password, secret) VALUES 
(1, 'admin', 'admin', '1234567890'),
(2, 'tester', 'tester', '0987654321');

INSERT INTO characters (id, name, health, experience, gold, guild_id, updated_at) VALUES 
(1, 'Админ', 20, 100, 100, NULL, NOW()),
(2, 'Тестер', 20, 100, 100, NULL, NOW());

INSERT INTO guilds (id, name, level_required, leader_id) VALUES 
(1, 'Тестовая гильдия', 0, 1);

UPDATE characters SET guild_id = 1;

INSERT INTO inventories (character_id, size, items) VALUES 
(1, 24, '{}'),
(2, 24, '{2}');

INSERT INTO equipments (character_id, helmet_id, platebody_id, platelegs_id, boots_id, sword_id, shield_id) VALUES 
(1, NULL, 2, 9, 10, 11, 2),
(2, 1, 2, NULL, NULL, 5, 12);

