-- Tables
CREATE TABLE Enemies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    Name TEXT  NOT NULL,
    HealthPoints INTEGER NOT NULL,
    AttackPoints INTEGER NOT NULL,
    AsciiImage TEXT  NOT NULL,
    DroppableExperiencePoints INTEGER NOT NULL
);

-- Example data-sets
INSERT INTO Enemies (Name, HealthPoints, AttackPoints, AsciiImage, DroppableExperiencePoints)
VALUES ('Hoot', 100, 4, '-- Hoot Ascii Image --', 120),
('Woof', 120, 5, '-- Woof Ascii Image --', 100),
('Carpa', 50, 3, '-- Capra Ascii Image --', 50),
('Snek', 150, 9, '-- Snek Ascii Image --', 200),
('Abraka', 180, 12, '-- Abraka Ascii Image --', 180);
