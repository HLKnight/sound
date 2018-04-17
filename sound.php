<?php
$log_file = 'sound_log.txt';
$data = $_POST['data'];
$today = date("d/m/Y H:i:s");
//date_default_timezone_set("UTC+02");
$str = $today .', '. $data ."\n";
// now we open the file
if(file_exists($log_file))
{
	$fp = fopen($log_file, "a");	// the file is opened in append mode
	fwrite($fp, $str);
	fclose($fp);
}
else							// the file doesn't exist, so open a new one
{
	$fp = fopen($log_file, "w");
	fwrite($fp, $str);
	fclose($fp);
}
echo "Data is stored\n";
?>