----------------------------------------------------------------------------------
---------------------------------( ASSIGNMENT 1 )---------------------------------
----------------------------------------------------------------------------------

---------------------------------( TEAM table )-----------------------------------
CREATE TABLE TEAM (
    Team_ID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Home_Stadium VARCHAR(50) NOT NULL,
    Wins INT DEFAULT 0,
    Losses INT DEFAULT 0
);

INSERT INTO TEAM (Team_ID, Name, Home_Stadium, Wins, Losses)
VALUES
(1, 'Karachi Kings', 'National Stadium', 0, 0),
(2, 'Lahore Qalandars', 'Gaddafi Stadium', 0, 0),
(3, 'Islamabad United', 'Rawalpindi Cricket Stadium', 0, 0),
(4, 'Peshawar Zalmi', 'Arbab Niaz Stadium', 0, 0),
(5, 'Quetta Gladiators', 'Bugti Stadium', 0, 0),
(6, 'Multan Sultans', 'Multan Cricket Stadium', 0, 0);

-- Update query to update team win and loss status using winner table
UPDATE TEAM
SET
    Wins = (SELECT COUNT(*) FROM WINNER WHERE Winning_Team_ID = TEAM.Team_ID),
    Losses = (SELECT COUNT(*) FROM MATCH
              WHERE (Team1_ID = TEAM.Team_ID OR Team2_ID = TEAM.Team_ID)
              AND Match_ID NOT IN (SELECT Match_ID FROM WINNER WHERE Winning_Team_ID = TEAM.Team_ID));


---------------------------------( PLAYER table )-----------------------------------
CREATE TABLE PLAYER 
(
    Player_ID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Role VARCHAR(50) NOT NULL,
    Team_ID INT,  FOREIGN KEY (Team_ID) REFERENCES TEAM(Team_ID)
);

INSERT INTO PLAYER (Player_ID, Name, Role, Team_ID)
VALUES
(1, 'Babar Azam', 'Batsman', 1),
(2, 'Shaheen Afridi', 'Bowler', 2),
(3, 'Shadab Khan', 'All-Rounder', 3),
(4, 'Wahab Riaz', 'Bowler', 4),
(5, 'Sarfaraz Ahmed', 'Wicketkeeper', 5),
(6, 'Mohammad Rizwan', 'Wicketkeeper', 6),
(7, 'Imad Wasim', 'All-Rounder', 1),
(8, 'Fakhar Zaman', 'Batsman', 2),
(9, 'Asif Ali', 'Batsman', 3),
(10, 'Haris Rauf', 'Bowler', 4),
(11, 'Hassan Ali', 'Bowler', 5),
(12, 'Faheem Ashraf', 'All-Rounder', 6),
(13, 'Mohammad Hafeez', 'All-Rounder', 1),
(14, 'Shoaib Malik', 'All-Rounder', 2),
(15, 'Ahmed Shehzad', 'Batsman', 3),
(16, 'Umar Akmal', 'Batsman', 4),
(17, 'Shan Masood', 'Batsman', 5),
(18, 'Kamran Akmal', 'Wicketkeeper', 6),
(19, 'Yasir Shah', 'Bowler', 1),
(20, 'Junaid Khan', 'Bowler', 2);

---------------------------------( STADIUM table )-----------------------------------
CREATE TABLE STADIUM (
    Stadium_ID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Location VARCHAR(100) NOT NULL,
    Capacity INT NOT NULL
);

INSERT INTO STADIUM (Stadium_ID, Name, Location, Capacity)
VALUES
(1, 'National Stadium', 'Karachi', 25000),
(2, 'Gaddafi Stadium', 'Lahore', 27000),
(3, 'Rawalpindi Cricket Stadium', 'Rawalpindi', 28000),
(4, 'Multan Cricket Stadium', 'Multan', 30000),
(5, 'Rawalpindi Stadium', 'Islamabad', 26000),
(6, 'Bugti Stadium', 'Quetta', 23000);

---------------------------------( MATCH table )-----------------------------------
CREATE TABLE MATCH (
    Match_ID INT PRIMARY KEY,
    Date DATE NOT NULL,
    Time TIME NOT NULL,
    Stadium_ID INT,
    Match_Type VARCHAR(20) NOT NULL,
    Team1_ID INT,
    Team2_ID INT,
    FOREIGN KEY (Stadium_ID) REFERENCES STADIUM(Stadium_ID),
    FOREIGN KEY (Team1_ID) REFERENCES TEAM(Team_ID),
    FOREIGN KEY (Team2_ID) REFERENCES TEAM(Team_ID)
);

INSERT INTO MATCH (Match_ID, Date, Time, Stadium_ID, Match_Type, Team1_ID, Team2_ID)
VALUES
(1, '2024-03-01', '15:00:00', 1, 'Qualifier', 1, 2),
(2, '2024-03-02', '15:00:00', 2, 'Eliminator', 3, 4),
(3, '2024-03-03', '15:00:00', 3, 'Eliminator', 5, 6),
(4, '2024-03-04', '15:00:00', 4, 'Final', 1, 3),
(5, '2024-03-05', '15:00:00', 1, 'Qualifier', 2, 3),
(6, '2024-03-06', '15:00:00', 2, 'Eliminator', 4, 5),
(7, '2024-03-07', '15:00:00', 3, 'Eliminator', 6, 1),
(8, '2024-03-08', '15:00:00', 4, 'Final', 3, 5),
(9, '2024-03-09', '15:00:00', 1, 'Qualifier', 1, 4),
(10, '2024-03-10', '15:00:00', 2, 'Eliminator', 2, 6),
(11, '2024-03-11', '15:00:00', 3, 'Eliminator', 3, 4),
(12, '2024-03-12', '15:00:00', 4, 'Final', 1, 6),
(13, '2024-03-13', '15:00:00', 1, 'Qualifier', 2, 5),
(14, '2024-03-14', '15:00:00', 2, 'Eliminator', 4, 6),
(15, '2024-03-15', '15:00:00', 3, 'Eliminator', 1, 3),
(16, '2024-03-16', '15:00:00', 4, 'Final', 2, 4),
(17, '2024-03-17', '15:00:00', 1, 'Qualifier', 3, 6),
(18, '2024-03-18', '15:00:00', 2, 'Eliminator', 1, 5),
(19, '2024-03-19', '15:00:00', 3, 'Eliminator', 2, 4),
(20, '2024-03-20', '15:00:00', 4, 'Final', 3, 6);

------------------------------------( PERFORMANCE table )------------------------------
CREATE TABLE PERFORMANCE (
    Performance_ID INT PRIMARY KEY,
    Match_ID INT,
    Player_ID INT,
    Runs_Scored INT,
    Wickets_Taken INT,
    Catches INT,
    FOREIGN KEY (Match_ID) REFERENCES MATCH(Match_ID),
    FOREIGN KEY (Player_ID) REFERENCES PLAYER(Player_ID)
);

INSERT INTO PERFORMANCE (Performance_ID, Match_ID, Player_ID, Runs_Scored, Wickets_Taken, Catches)
VALUES
(1, 1, 1, 78, 0, 1),    -- Player 1's performance in Match 1
(2, 1, 2, 0, 2, 0),     -- Player 2's performance in Match 1
(3, 1, 3, 45, 1, 0),    -- Player 3's performance in Match 1
(4, 2, 4, 102, 1, 2),   -- Player 4's performance in Match 2
(5, 2, 5, 56, 0, 1),    -- Player 5's performance in Match 2
(6, 2, 6, 0, 3, 0),     -- Player 6's performance in Match 2
(7, 3, 7, 23, 0, 0),    -- Player 7's performance in Match 3
(8, 3, 8, 37, 2, 1),    -- Player 8's performance in Match 3
(9, 3, 9, 0, 1, 0),     -- Player 9's performance in Match 3
(10, 4, 10, 67, 1, 0),  -- Player 10's performance in Match 4
(11, 4, 11, 0, 0, 2),   -- Player 11's performance in Match 4
(12, 4, 12, 0, 2, 1),   -- Player 12's performance in Match 4
(13, 5, 13, 88, 1, 0),  -- Player 13's performance in Match 5
(14, 5, 14, 45, 0, 1),  -- Player 14's performance in Match 5
(15, 5, 15, 0, 3, 0),   -- Player 15's performance in Match 5
(16, 6, 16, 78, 0, 0),  -- Player 16's performance in Match 6
(17, 6, 17, 0, 2, 1),   -- Player 17's performance in Match 6
(18, 6, 18, 34, 1, 0),  -- Player 18's performance in Match 6
(19, 7, 19, 67, 1, 0),  -- Player 19's performance in Match 7
(20, 7, 20, 0, 0, 2),   -- Player 20's performance in Match 7
(21, 8, 1, 102, 0, 0),  -- Player 1's performance in Match 8
(22, 8, 2, 0, 3, 1),    -- Player 2's performance in Match 8
(23, 8, 3, 67, 1, 0),   -- Player 3's performance in Match 8
(24, 9, 4, 45, 0, 1),   -- Player 4's performance in Match 9
(25, 9, 5, 0, 2, 0),    -- Player 5's performance in Match 9
(26, 9, 6, 78, 1, 2),   -- Player 6's performance in Match 9
(27, 10, 7, 0, 0, 2),   -- Player 7's performance in Match 10
(28, 10, 8, 56, 1, 0),  -- Player 8's performance in Match 10
(29, 10, 9, 0, 3, 1),   -- Player 9's performance in Match 10
(30, 11, 10, 102, 0, 1),-- Player 10's performance in Match 11
(31, 11, 11, 23, 1, 0), -- Player 11's performance in Match 11
(32, 11, 12, 0, 2, 1),  -- Player 12's performance in Match 11
(33, 12, 13, 67, 0, 0), -- Player 13's performance in Match 12
(34, 12, 14, 0, 1, 0),  -- Player 14's performance in Match 12
(35, 12, 15, 45, 2, 1), -- Player 15's performance in Match 12
(36, 13, 16, 0, 0, 2),  -- Player 16's performance in Match 13
(37, 13, 17, 88, 1, 0), -- Player 17's performance in Match 13
(38, 13, 18, 56, 0, 1), -- Player 18's performance in Match 13
(39, 14, 19, 0, 1, 0),  -- Player 19's performance in Match 14
(40, 14, 20, 34, 0, 2), -- Player 20's performance in Match 14
(41, 14, 1, 56, 2, 0),  -- Player 1's performance in Match 14
(42, 15, 2, 0, 0, 2),   -- Player 2's performance in Match 15
(43, 15, 3, 78, 1, 1),  -- Player 3's performance in Match 15
(44, 15, 4, 56, 0, 0),  -- Player 4's performance in Match 15
(45, 16, 5, 0, 2, 1),   -- Player 5's performance in Match 16
(46, 16, 6, 102, 1, 0), -- Player 6's performance in Match 16
(47, 16, 7, 45, 0, 1),  -- Player 7's performance in Match 16
(48, 17, 8, 78, 1, 0),  -- Player 8's performance in Match 17
(49, 17, 9, 0, 0, 2),   -- Player 9's performance in Match 17
(50, 17, 10, 56, 2, 1), -- Player 10's performance in Match 17
(51, 18, 1, 89, 0, 1),    -- Player 1's performance in Match 18
(52, 18, 2, 0, 2, 0),     -- Player 2's performance in Match 18
(53, 18, 3, 34, 1, 0),    -- Player 3's performance in Match 18
(54, 18, 4, 77, 1, 1),    -- Player 4's performance in Match 18
(55, 18, 5, 0, 0, 2),     -- Player 5's performance in Match 18
(56, 18, 6, 56, 0, 1),    -- Player 6's performance in Match 18
(57, 18, 7, 0, 1, 0),     -- Player 7's performance in Match 18
(58, 18, 8, 78, 2, 1),    -- Player 8's performance in Match 18
(59, 18, 9, 102, 0, 0),   -- Player 9's performance in Match 18
(60, 18, 10, 45, 1, 0),   -- Player 10's performance in Match 18
(61, 19, 11, 23, 0, 0),   -- Player 11's performance in Match 19
(62, 19, 12, 67, 2, 1),   -- Player 12's performance in Match 19
(63, 19, 13, 0, 1, 0),    -- Player 13's performance in Match 19
(64, 19, 14, 45, 0, 1),   -- Player 14's performance in Match 19
(65, 19, 15, 0, 3, 0),    -- Player 15's performance in Match 19
(66, 19, 16, 78, 0, 0),   -- Player 16's performance in Match 19
(67, 19, 17, 0, 2, 1),    -- Player 17's performance in Match 19
(68, 19, 18, 34, 1, 0),   -- Player 18's performance in Match 19
(69, 19, 19, 56, 0, 1),   -- Player 19's performance in Match 19
(70, 19, 20, 0, 0, 2),    -- Player 20's performance in Match 19
(71, 20, 1, 102, 0, 1),   -- Player 1's performance in Match 20
(72, 20, 2, 23, 1, 0),    -- Player 2's performance in Match 20
(73, 20, 3, 0, 2, 1),     -- Player 3's performance in Match 20
(74, 20, 4, 67, 0, 0),    -- Player 4's performance in Match 20
(75, 20, 5, 45, 1, 0),    -- Player 5's performance in Match 20
(76, 20, 6, 88, 0, 1),    -- Player 6's performance in Match 20
(77, 20, 7, 0, 3, 0),     -- Player 7's performance in Match 20
(78, 20, 8, 20, 1, 0),    -- Player 8's performance in Match 20 
(79, 20, 9, 56, 0, 1),    -- Player 9's performance in Match 20
(80, 20, 10, 0, 0, 2);    -- Player 10's performance in Match 20

---------------------------------( WINNER table )-----------------------------------
CREATE TABLE WINNER (
    Match_ID INT PRIMARY KEY,
    Winning_Team_ID INT,
    FOREIGN KEY (Match_ID) REFERENCES MATCH(Match_ID),
    FOREIGN KEY (Winning_Team_ID) REFERENCES TEAM(Team_ID)
);

INSERT INTO WINNER (Match_ID, Winning_Team_ID)
VALUES
(1, 1),   -- Match 1 winner: Karachi Kings
(2, 4),   -- Match 2 winner: Peshawar Zalmi
(3, 5),   -- Match 3 winner: Quetta Gladiators
(4, 1),   -- Match 4 winner: Karachi Kings
(5, 2),   -- Match 5 winner: Lahore Qalandars
(6, 4),   -- Match 6 winner: Peshawar Zalmi
(7, 6),   -- Match 7 winner: Multan Sultans
(8, 3),   -- Match 8 winner: Islamabad United
(9, 1),   -- Match 9 winner: Karachi Kings
(10, 6),  -- Match 10 winner: Multan Sultans
(11, 4),  -- Match 11 winner: Peshawar Zalmi
(12, 1),  -- Match 12 winner: Karachi Kings
(13, 3),  -- Match 13 winner: Islamabad United
(14, 6),  -- Match 14 winner: Multan Sultans
(15, 1),  -- Match 15 winner: Karachi Kings
(16, 2),  -- Match 16 winner: Lahore Qalandars
(17, 6),  -- Match 17 winner: Multan Sultans
(18, 1),  -- Match 18 winner: Karachi Kings
(19, 4),  -- Match 19 winner: Peshawar Zalmi
(20, 6);  -- Match 20 winner: Multan Sultans


SELECT * FROM TEAM
SELECT * FROM PLAYER
SELECT * FROM STADIUM
SELECT * FROM MATCH
SELECT * FROM WINNER
SELECT * FROM PERFORMANCE


--Q2--
SELECT TOP 1 Name AS Player_Name, SUM(Catches) AS Total_Catches FROM PLAYER
	INNER JOIN PERFORMANCE ON PLAYER.Player_ID = PERFORMANCE.Player_ID
		GROUP BY PLAYER.Name
		ORDER BY Total_Catches DESC;

--Q3--
SELECT CONCAT(Home_Stadium, ' in ',Name) AS Home_Stadium
FROM TEAM;

--Q4--
SELECT STADIUM.Name, STADIUM.Capacity FROM STADIUM
-- SELECT STADIUM.Name, STADIUM.Capacity FROM STADIUM WHERE NAME='FOR SPECIFIC'

--Q5--
SELECT TEAM.Name AS Team,PLAYER.Name AS Player_Name, AVG(PERFORMANCE.Runs_Scored) AS AVG_RUN FROM PERFORMANCE 
	JOIN PLAYER ON PLAYER.Player_ID=PERFORMANCE.Player_ID
		JOIN TEAM ON TEAM.Team_ID = PLAYER.Team_ID
			GROUP BY TEAM.Name,PLAYER.Name
				ORDER BY TEAM.Name

--Q6--
SELECT COUNT(*) AS Matches_Played FROM MATCH
WHERE Stadium_ID = (SELECT Stadium_ID FROM STADIUM WHERE Name = 'National Stadium');

--Q7--
SELECT TEAM.Name AS Team,PLAYER.Name AS Player_Name, SUM(PERFORMANCE.Runs_Scored) AS TOTAL_RUN FROM PERFORMANCE 
	JOIN PLAYER ON PLAYER.Player_ID=PERFORMANCE.Player_ID
		JOIN TEAM ON TEAM.Team_ID = PLAYER.Team_ID
			GROUP BY TEAM.Name,PLAYER.Name
				ORDER BY TEAM.Name

--Q8--
SELECT TEAM.Name,TEAM.Wins FROM TEAM
WHERE Wins > 3;

--Q9--
SELECT PLAYER.Name,PLAYER.Player_ID,TEAM.Name FROM PLAYER 
	JOIN TEAM ON TEAM.Team_ID=PLAYER.Team_ID
		WHERE Role = 'Bowler';

--Q10--
SELECT PLAYER.Player_ID,PLAYER.Name,TEAM.Name,PERFORMANCE.Wickets_Taken,PERFORMANCE.Runs_Scored FROM PERFORMANCE 
	JOIN PLAYER ON PERFORMANCE.Player_ID=PLAYER.Player_ID
		JOIN TEAM ON TEAM.Team_ID=PLAYER.Team_ID
			WHERE Runs_Scored>50 AND Wickets_Taken>2

--Q11--
SELECT TOP 1 TEAM.Name AS Team_Name, SUM(PERFORMANCE.Runs_Scored) AS Total_Runs_Scored FROM TEAM
	JOIN PLAYER ON TEAM.Team_ID = PLAYER.Team_ID
		JOIN PERFORMANCE ON PLAYER.Player_ID = PERFORMANCE.Player_ID
			GROUP BY TEAM.Name
			ORDER BY Total_Runs_Scored DESC

--Q12--	
SELECT MATCH.Match_ID, MATCH.Date, MATCH.Match_Type,TEAM.Name FROM MATCH 
	JOIN WINNER ON WINNER.Match_ID=MATCH.Match_ID
		JOIN TEAM ON TEAM.Team_ID=WINNER.Winning_Team_ID

--Q13--
SELECT DISTINCT Match_Type FROM MATCH
	WHERE Match_Type IN ('Qualifier', 'Eliminator', 'Final');

--Q14--
SELECT STADIUM.Name, COUNT(MATCH.Stadium_ID) AS Matches_Played FROM STADIUM 
	JOIN MATCH ON STADIUM.Stadium_ID=MATCH.Stadium_ID
	GROUP BY STADIUM.Stadium_ID,STADIUM.Name

--Q15--
SELECT PLAYER.* FROM PLAYER JOIN TEAM ON TEAM.Team_ID=PLAYER.Team_ID
WHERE TEAM.Name ='Lahore Qalandars'

--Q16--
SELECT TOP 3 Name AS Player_Name, SUM(per.Runs_Scored) AS Total_Runs_Scored FROM PLAYER
	JOIN PERFORMANCE per ON PLAYER.Player_ID = per.Player_ID
		JOIN MATCH m ON per.Match_ID = m.Match_ID
			WHERE m.Match_Type = 'Final'
				GROUP BY PLAYER.Name
				ORDER BY Total_Runs_Scored DESC;

--Q17--
SELECT PERFORMANCE.Match_ID, PLAYER.Player_ID,PLAYER.Name,TEAM.Name,PERFORMANCE.Runs_Scored FROM PERFORMANCE 
	JOIN PLAYER ON PERFORMANCE.Player_ID=PLAYER.Player_ID
		JOIN TEAM ON TEAM.Team_ID=PLAYER.Team_ID
			JOIN WINNER ON WINNER.Match_ID=PERFORMANCE.Match_ID
				WHERE Runs_Scored>50 


--Q18--
SELECT TOP 3 p.Name AS Player_Name, SUM(per.Runs_Scored) AS Total_Runs_Scored FROM PLAYER p
	JOIN PERFORMANCE per ON p.Player_ID = per.Player_ID
		JOIN MATCH m ON per.Match_ID = m.Match_ID
			GROUP BY p.Name
			ORDER BY Total_Runs_Scored DESC;
--Q19--
SELECT T.Name AS Team_Name, s.Name AS Stadium_Name, AVG(per.Runs_Scored) AS Average_Runs_Scored, AVG(per.Wickets_Taken) AS Average_Wickets_Taken FROM TEAM T
	JOIN PLAYER P ON T.Team_ID = P.Team_ID
		JOIN PERFORMANCE per ON P.Player_ID = per.Player_ID
			JOIN MATCH M ON per.Match_ID = M.Match_ID
				JOIN STADIUM S ON M.Stadium_ID = S.Stadium_ID
					GROUP BY T.Name, S.Name;

--Q20--
SELECT TEAM.Name, TEAM.Home_Stadium,COUNT(*) as Wins FROM WINNER 
	JOIN TEAM ON TEAM.Team_ID=WINNER.Winning_Team_ID
		JOIN MATCH ON MATCH.Match_ID=WINNER.Match_ID
			GROUP BY TEAM.Name,TEAM.Home_Stadium

--Q21--
SELECT TEAM.Team_ID,TEAM.Name,TEAM.Wins FROM TEAM
	

--Q22--
SELECT DISTINCT P.Name AS Player_Name FROM PLAYER P
	JOIN PERFORMANCE per ON P.Player_ID = per.Player_ID
		JOIN WINNER W ON per.Match_ID = W.Match_ID
			WHERE per.Runs_Scored > 50 OR per.Wickets_Taken >= 3 OR per.Catches > 2;

--Q23--
--COREALTED NESTED QUERIES--
SELECT Name AS Player_Name,
       (SELECT COUNT(*) FROM PERFORMANCE per WHERE per.Player_ID = p.Player_ID) AS Total_Matches_Played
FROM PLAYER p;
--TO PERFORM OPERATIONS ON DATA FROM RELATED TABLES

--UNION--
SELECT Name FROM PLAYER WHERE Role='Bowler'
	UNION
		SELECT Name FROM PLAYER WHERE Role='All-Rounder'
		--COMBINE RESULT OF 2 OR MORE QUERIES/TABLES--

--GROUP BY--
SELECT Team_ID, COUNT(*) AS Total_Players
FROM PLAYER
GROUP BY Team_ID;
--USED WIH AGGREGATE FUNCTIONS--

--Substring comparison using LIKE--
SELECT Name FROM PLAYER WHERE Name LIKE 'A%';
--TO PERFORM PARTIAL STRING MATCHING--

--Having--
SELECT Team_ID, COUNT(*) AS Total_Players
FROM PLAYER
GROUP BY Team_ID
HAVING COUNT(*) > 3;
--TO PLACE CONDITIONS AFTER GROUP BY--