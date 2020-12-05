<!DOCTYPE html>
<html><body>
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

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

// sql script. Selects all data from database along with all columns starting from most recent data collected
$sql = "SELECT id, plant, dataTemperature, dataHumidity, dataLight, dataSoilMoisture, reading_time FROM SensorData ORDER BY id DESC";

// table with database catergories created, no data added yet
echo '<table cellspacing="5" cellpadding="5">
      <tr> 
        <td>ID</td> 
        <td>Plant</td> 
        <td>DataTemperature</td> 
        <td>DataHumidity</td> 
        <td>DataLight</td>
        <td>DataSoilMoisture</td> 
        <td>Timestamp</td> 
      </tr>';

// perform query on database
if ($result = $conn->query($sql)) {
    // row var contains one row from database
    // will repeat for each value row in database
    while ($row = $result->fetch_assoc()) {
      // set data from database row to variables
        $row_id = $row["id"];
        $row_plant = $row["plant"];
        $row_dataTemperature = $row["dataTemperature"];
        $row_dataHumidity = $row["dataHumidity"];
        $row_dataLight = $row["dataLight"]; 
        $row_dataSoilMoisture = $row["dataSoilMoisture"]; 
        $row_reading_time = $row["reading_time"];
      
        // fill in table with database values
        echo '<tr> 
                <td>' . $row_id . '</td> 
                <td>' . $row_plant . '</td> 
                <td>' . $row_dataTemperature . '</td> 
                <td>' . $row_dataHumidity . '</td> 
                <td>' . $row_dataLight . '</td>
                <td>' . $row_dataSoilMoisture . '</td> 
                <td>' . $row_reading_time . '</td> 
              </tr>';
    }
    $result->free();
}

$conn->close();
?> 
</table>
</body>
</html>
