<?php

/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-esp8266-mysql-database-php/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

$servername = "localhost";

// Database name
$dbname = "esp-data";
// Database user
$username = "";
// Database user password
$password = "";

// Keep this API Key value to be compatible with the ESP32 code provided in the project page. 
// If you change this value, the ESP32 sketch needs to match
$api_key_value = "tPmAT5Ab3j7F9";

$api_key= $plant = $dataTemperature = $dataHumidity = $dataLight = $dataSoilMoisture = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $api_key = test_input($_POST["api_key"]);
    if($api_key == $api_key_value) {
        $plant = test_input($_POST["plant"]);
        $dataTemperature = test_input($_POST["dataTemperature"]);
        $dataHumidity = test_input($_POST["dataHumidity"]);
        $dataLight = test_input($_POST["dataLight"]);
        $dataSoilMoisture = test_input($_POST["dataSoilMoisture"]);
        
        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } 
        
        // each of the 5 values is being being inserted into its corresponding database column
        $sql = "INSERT INTO SensorData (plant, dataTemperature, dataHumidity, dataLight, dataSoilMoisture)
        VALUES ('" . $plant . "', '" . $dataTemperature . "', '" . $dataHumidity . "', '" . $dataLight . "', '" . $dataSoilMoisture . "')";
        
        if ($conn->query($sql) === TRUE) {
            echo "New record created successfully";
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    
        $conn->close();
    }
    else {
        echo "Wrong API Key provided.";
    }

}
else {
    echo "No data posted with HTTP POST.";
}

// parses data
function test_input($data) {
    $data = trim($data); // removes whitespace from begining and end of string
    $data = stripslashes($data); // removes quotes from string
    $data = htmlspecialchars($data);
    return $data;
}
