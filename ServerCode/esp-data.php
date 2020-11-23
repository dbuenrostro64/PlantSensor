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

// REPLACE with your Database name
$dbname = "esp-data";
// REPLACE with Database user
$username = "dbuenrostro64";
// REPLACE with Database user password
$password = "Bloocool091897@";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "SELECT id, plant, dataTemperature, dataHumidity, dataLight, dataSoilMoisture, reading_time FROM SensorData ORDER BY id DESC";

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
 
if ($result = $conn->query($sql)) {
    while ($row = $result->fetch_assoc()) {
        $row_id = $row["id"];
        $row_plant = $row["plant"];
        $row_dataTemperature = $row["dataTemperature"];
        $row_dataHumidity = $row["dataHumidity"];
        $row_dataLight = $row["dataLight"]; 
        $row_dataSoilMoisture = $row["dataSoilMoisture"]; 
        $row_reading_time = $row["reading_time"];
        // Uncomment to set timezone to - 1 hour (you can change 1 to any number)
        //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time - 1 hours"));
      
        // Uncomment to set timezone to + 4 hours (you can change 4 to any number)
        //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time + 4 hours"));
      
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
