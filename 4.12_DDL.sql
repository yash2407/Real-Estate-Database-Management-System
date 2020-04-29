CREATE SCHEMA RealEstate1;
SET SEARCH_PATH TO RealEstate1;

CREATE TABLE customerDetails(
    Verification_Id varchar(16) PRIMARY KEY,
    "Name" varchar(100) NOT NULL,
    Email varchar(100) NOT NULL,
    City varchar(25)  NOT NULL,
    Age Integer NOT NULL,
    Gender varchar(6) NOT NULL,
    Address varchar(500) NOT NULL,
    Budget Integer,
    Type_of_customer varchar(10) NOT NULL
);

CREATE TABLE LoginDetails(
    Login_ID varchar(16) ,
    Verification_ID varchar(16),
    "Password" varchar(20) NOT NULL,
    Contact_No DECIMAL(10,0) NOT NULL,
    FOREIGN KEY (Verification_ID ) REFERENCES customerDetails(Verification_Id) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY (Login_ID ,Verification_ID)
);

CREATE TABLE Property(
    Property_ID DECIMAL(10,0) PRIMARY KEY,
    PropertyName varchar(12) NOT NULL,
    Owner_ID varchar(16) NOT NULL,
    "Location" varchar(255) NOT NULL,
    ConstructionStatus varchar(12),
    BookingStatus varchar(12) NOT NULL,
    FOREIGN KEY (Owner_ID) REFERENCES customerDetails(Verification_Id) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE PropertyType(
    Property_ID DECIMAL(10,0),
    "Type" varchar(12),
    Sales_type varchar(20),
    Amount Integer NOT NULL,
    Contract_Period varchar(20) NOT NULL,
    BHK Integer,
    Carpet_area Integer NOT NULL,
    "Floor" Integer,
    subtype varchar(25),
    FOREIGN KEY (Property_ID) REFERENCES Property(Property_ID) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY (Property_ID, "Type" ,Sales_type)
);

CREATE TABLE Feedback(
    Feedback_ID DECIMAL(10,0) PRIMARY KEY,
    Respondent varchar(16) NOT NULL,
    Property_ID DECIMAL(10,0) NOT NULL,
    Rating DECIMAL(1,0) NOT NULL,
    Description varchar(255),
    FOREIGN KEY (Respondent) REFERENCES customerDetails(Verification_Id) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (Property_ID) REFERENCES Property(Property_ID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE BookingDetails(
    Booking_ID decimal(10,0) PRIMARY KEY,
    Property_ID DECIMAL(10,0) NOT NULL,
    Buyer_ID varchar(16) NOT NULL,
    Seller_ID varchar(16) NOT NULL,
    Date_of_Booking date NOT NULL,
    Selling_price Integer NOT NULL,
    FOREIGN KEY (Buyer_ID) REFERENCES customerDetails(Verification_Id) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (Property_ID) REFERENCES Property(Property_ID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (Seller_ID) REFERENCES customerDetails(Verification_Id) ON DELETE CASCADE ON UPDATE CASCADE
);