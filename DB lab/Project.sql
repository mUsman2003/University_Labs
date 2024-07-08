Drop table Person
CREATE TABLE Person (
    Person_ID NVARCHAR(255) PRIMARY KEY,
    Phone NVARCHAR(255),
    F_name NVARCHAR(255),
    L_Name NVARCHAR(255),
    M_Name NVARCHAR(255),
    Addresss NVARCHAR(255),
    DoB DATETIME,
    Age Float,
    Username NVARCHAR(255),
    Passwordd NVARCHAR(255),
    Rolee NVARCHAR(255)
);

Insert Into [dbo].[Person](Person_ID,phone,F_name,L_Name,M_Name, Addresss,DOB, Age,Username, Passwordd,Rolee)
Select Person_ID,phone,F_name,L_Name,M_Name, Addresss,DOB, Age,Username, Passwordd,Rolee from [dbo].[Person$]

Select* from Person