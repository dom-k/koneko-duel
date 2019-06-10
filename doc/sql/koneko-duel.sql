-- Tables
CREATE TABLE Enemies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    Name TEXT  NOT NULL,
    AsciiImage TEXT  NOT NULL,
    DroppableExperiencePoints INTEGER NOT NULL
);

CREATE TABLE TestTable (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    Prename TEXT NOT NULL,
    Name TEXT NOT NULL,
    EMail TEXT NOT NULL,
    Username TEXT NOT NULL,
    Password TEXT
);


-- Example data-sets
INSERT INTO Enemies (Name, AsciiImage, DroppableExperiencePoints)
VALUES ('Hoot', '-- Hoot Ascii Image --', 120),
('Woof', '-- Woof Ascii Image --', 100),
('Carpa', '-- Capra Ascii Image --', 50),
('Snek', '-- Snek Ascii Image --', 200),
('Abraka', '-- Abraka Ascii Image --', 180);

INSERT INTO TestTable (Prename, Name, EMail, Username, Password)
VALUES("Dominik", "K", "kdominik@gmail.com", "kdominik", "password"),
("Donald", "D", "ddonald@gmail.com", "ddonald", "pass123"),
("Dagobert", "D", "ddagobert@gmail.com", "ddagobert", "123456");