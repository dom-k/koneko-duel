CREATE TABLE Enemies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    Name TEXT  NOT NULL,
    AsciiImage TEXT  NOT NULL,
    DroppableExperiencePoints INTEGER NOT NULL
);


-- Example data-sets
INSERT INTO Enemies (Name, AsciiImage, DroppableExperiencePoints)
VALUES ('Hoot', '-- Hoot Ascii Image --', 120),
('Woof', '-- Woof Ascii Image --', 100),
('Carpa', '-- Capra Ascii Image --', 50),
('Snek', '-- Snek Ascii Image --', 200),
('Abraka', '-- Abraka Ascii Image --', 180);
