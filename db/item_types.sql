DROP TABLE IF EXISTS item_types;
DROP TYPE IF EXISTS item_kind;
CREATE TYPE item_kind AS ENUM (
    'helmet', 
    'platebody', 
    'platelegs', 
    'boots', 
    'sword', 
    'shield'
);
CREATE TABLE item_types (
    id INTEGER PRIMARY KEY,
    image VARCHAR NOT NULL,
    name VARCHAR NOT NULL,
    level INTEGER NOT NULL,
    attack INTEGER NOT NULL,
    defense INTEGER NOT NULL,
    kind item_kind NOT NULL,
    buy_price INTEGER NOT NULL
    sell_price INTEGER NOT NULL
);
INSERT INTO item_types 
(image, name, level, attack, defense, buy_price, sell_price) VALUES
('BronzeSword.png', 'Бронзовый меч', 1, 5, 0, 'sword', 200, 100),
('BronzeShield.png', 'Бронзовый щит', 1, 0, 5, 'shield', 200, 100),
('BronzeHelmet.png', 'Бронзовый шлем', 1, 0, 5, 'helmet', 200, 100),
('BronzePlatebody.png', 'Бронзовый нагрудник', 1, 0, 5, 'platebody', 200, 100),
('BronzePlatelegs.png', 'Бронзовые поножи', 1, 0, 5, 'platelegs', 200, 100),
('BronzeBoots.png', 'Бронзовые ботинки', 1, 0, 5, 'boots', 200, 100),
('IronSword.png', 'Железный меч', 5, 15, 0, 'sword', 500, 250),
('IronShield.png', 'Железный щит', 5, 0, 15, 'shield', 500, 250),
('IronHelmet.png', 'Железный шлем', 5, 0, 15, 'helmet', 500, 250),
('IronPlatebody.png', 'Железный нагрудник', 5, 0, 15, 'platebody', 500, 250),
('IronPlateLegs.png', 'Железные поножи', 5, 0, 15, 'platelegs', 500, 250),
('IronBoots.png', 'Железные ботинки', 5, 0, 15, 'boots', 500, 250),
('SteelSword.png', 'Стальной меч', 10, 30, 0, 'sword', 1000, 500),
('SteelShield.png', 'Стальной щит', 10, 0, 30, 'shield', 1000, 500),
('SteelHelmet.png', 'Стальной шлем', 10, 0, 30, 'helmet', 1000, 500),
('SteelPlatebody.png', 'Стальной нагрудник', 10, 0, 30, 'platebody', 1000, 500),
('SteelPlatelegs.png', 'Стальные поножи', 10, 0, 30, 'platelegs', 1000, 500),
('SteelBoots.png', 'Стальные ботинки', 10, 0, 30, 'boots', 1000, 500),
('MithrilSword.png', 'Мифриловый меч', 15, 55, 0, 'sword', 2000, 1000),
('MithrilShield.png', 'Мифриловый щит', 15, 0, 55, 'shield', 2000, 1000),
('MithrilHelmet.png', 'Мифриловый шлем', 15, 0, 55, 'helmet', 2000, 1000),
('MithrilPlatebody.png', 'Мифриловый нагрудник', 15, 0, 55, 'platebody', 2000, 1000),
('MithrilPlatebody.png', 'Мифриловые поножи', 15, 0, 55, 'platelegs', 2000, 1000),
('MithrilBoots.png', 'Мифриловые ботинки', 15, 0, 55, 'boots', 2000, 1000),
('AdamantSword.png', 'Адамантовый меч', 25, 80, 0, 'sword', 5000, 2500),
('AdamantShield.png', 'Адамантовый щит', 25, 0, 80, 'shield', 5000, 2500),
('AdamantHelmet.png', 'Адамантовый шлем', 25, 0, 80, 'helmet', 5000, 2500),
('AdamantPlatebody.png', 'Адамантовый нагрудник', 25, 0, 80, 'platebody', 5000, 2500),
('AdamantPlatelegs.png', 'Адамантовые поножи', 25, 0, 80, 'platelegs', 5000, 2500),
('AdamantBoots.png', 'Адамантовые ботинки', 25, 0, 80, 'boots', 5000, 2500);
