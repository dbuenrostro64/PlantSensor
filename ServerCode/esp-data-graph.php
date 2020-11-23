<?php

$connect = mysqli_connect("localhost", "", "", "esp-data");
if (!$connect){
	echo "unable to connect to MySQL";
}

// Selects all data from database
$query = "SELECT * FROM SensorData";
$result = mysqli_query($connect, $query);
$chart_data = "";
// return string with a database row
// repeat for all rows
while($row = mysqli_fetch_array($result))
{
	// store row data in a chart
	// concatenation operator so new strings are added at the end
	$chart_data .= "{ reading_time:'".$row["reading_time"]."', 
					dataTemperature:".$row["dataTemperature"].", 
					dataHumidity:".$row["dataHumidity"].", 
					dataLight:".$row["dataLight"].", 
					dataSoilMoisture:".$row["dataSoilMoisture"]."}, ";
}
// returns chart_data with 2 chars ommited at the end and stores in var
$chart_data = substr($chart_data, 0, -2);
?>

<!DOCTYPE html>
<html>
	<head>
		<title> Plant Telemetry Chart</title>
		<link rel="stylesheet" href="esp-data-graph-style.css"/>
		<link rel="stylesheet" href="//cdnjs.cloudflare.com/ajax/libs/morris.js/0.5.1/morris.css"/>
		<!-- run javascript code for creating graphs -->
		<script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.0/jquery.min.js"></script>
		<script src="//cdnjs.cloudflare.com/ajax/libs/raphael/2.1.0/raphael-min.js"></script>
		<script src="//cdnjs.cloudflare.com/ajax/libs/morris.js/0.5.1/morris.min.js"></script>
		<meta charset=utf-8 />
	</head>

	<body>
		<h1 class="intro"> Plant Graphs :3 </h1>
		<div class"row">
			<!-- each div has an id where the graph will be placed -->
			<div class="col-sm-6 text-center">
				<label class="label label-success">Temperature</Label>
				<div id="chart-1"></div>
			</div>
			<div class="col-sm-6 text-center">
				<label class="label label-success">Humidity</Label>
				<div id="chart-2"></div>
			</div>
			<div class="col-sm-6 text-center">
				<label class="label label-success">Light</Label>
				<div id="chart-3"></div>
			</div>
			<div class="col-sm-6 text-center">
				<label class="label label-success">Soil Moisture</Label>
				<div id ="chart-4"></div>
			</div>
		
	</body>

</html>

<!-- javascript code -->
<script>

// adjust parameters for all graphs 1-4
var data = [<?php echo $chart_data; ?>]
config1 = {
	data: data,
	xkey: 'reading_time',
	ykeys: ['dataTemperature'],
	labels: ['Temperature'],
	lineColors: ['red']
	};
config2 = {
	data: data,
	xkey: 'reading_time',
	ykeys: ['dataHumidity'],
	labels: ['Humidity'],
	lineColors: ['green']
	};
config3 = {
	data: data,
	xkey: 'reading_time',
	ykeys: ['dataLight'],
	labels: ['Light'],
	lineColors: ['blue']
	};
config4 = {
	data: data,
	xkey: 'reading_time',
	ykeys: ['dataSoilMoisture'],
	labels: ['Soil Moisture'],
	lineColors: ['black']
	};
//4 line graphs placed in the corresponding html ids
config1.element = 'chart-1';
Morris.Line(config1);
config2.element  = 'chart-2';
Morris.Line(config2);
config3.element = 'chart-3';
Morris.Line(config3);
config4.element = 'chart-4';
Morris.Line(config4);
</script>
