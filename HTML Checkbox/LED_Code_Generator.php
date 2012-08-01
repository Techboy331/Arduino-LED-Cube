<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>LED CUBE Code Generation</title>
</head>

<body>
<?php

$totalstring = "int animate[4][4][4] = {";
$layer1string = "";
$layer2string = "";
$layer3string = "";
$layer4string = "";


$filled = false;
$layer1string .= "{";
	for ($i=23; $i<39; $i++)
	{
		if (($i-23)%4==0)
		{
			$layer1string .= "{";
			//echo ("hi");
		}
		$filled=false;
		for($j=0; $j<16; $j++)
		{
			
			if (isset($_POST['layer1'][$j]) && $_POST['layer1'][$j] == $i)
			{
				$layer1string .= $_POST['layer1'][$j] . ",";
				$filled = true;
			}
		}
		
		if (!$filled)
		{
			$layer1string .= "0,";
		}
		
		if (($i-22)%4==0)
		{
			$layer1string .= "},";
		}	
	}
$layer1string .= "},";
$filled = false;
$layer2string .= "{";
	for ($i=23; $i<39; $i++)
	{
		if (($i-23)%4==0)
		{
			$layer2string .= "{";
			//echo ("hi");
		}
		$filled=false;
		for($j=0; $j<16; $j++)
		{
			
			if (isset($_POST['layer2'][$j]) && $_POST['layer2'][$j] == $i)
			{
				$layer2string .= $_POST['layer2'][$j] . ",";
				$filled = true;
			}
		}
		
		if (!$filled)
		{
			$layer2string .= "0,";
		}
		
		if (($i-22)%4==0)
		{
			$layer2string .= "},";
		}	
	}
$layer2string .= "},";
$filled = false;
$layer3string .= "{";
	for ($i=23; $i<39; $i++)
	{
		if (($i-23)%4==0)
		{
			$layer3string .= "{";
			//echo ("hi");
		}
		$filled=false;
		for($j=0; $j<16; $j++)
		{
			
			if (isset($_POST['layer3'][$j]) && $_POST['layer3'][$j] == $i)
			{
				$layer3string .= $_POST['layer3'][$j] . ",";
				$filled = true;
			}
		}
		
		if (!$filled)
		{
			$layer3string .= "0,";
		}
		
		if (($i-22)%4==0)
		{
			$layer3string .= "},";
		}	
	}	
$layer3string .= "},";
$filled = false;
$layer4string .= "{";
	for ($i=23; $i<39; $i++)
	{
		if (($i-23)%4==0)
		{
			$layer4string .= "{";
			//echo ("hi");
		}
		$filled=false;
		for($j=0; $j<16; $j++)
		{
			
			if (isset($_POST['layer4'][$j]) && $_POST['layer4'][$j] == $i)
			{
				$layer4string .= $_POST['layer4'][$j] . ",";
				$filled = true;
			}
		}
		
		if (!$filled)
		{
			$layer4string .= "0,";
		}
		
		if (($i-22)%4==0)
		{
			$layer4string .= "},";
		}	
	}	
$layer4string .= "}};";
echo $totalstring;
echo $layer1string;
echo $layer2string;
echo $layer3string;
echo $layer4string;

/*
$index = 0;
$tracking_id = 23;
$layer1string .= "{";
for ($i=0; $i<4; $i++)
{
	$layer1string .= "{";
	for ($j = 0; $j<4; $j++)
	{
		
		if (isset($_POST['layer1'][$index]) ){
			$layer1string .= $_POST['layer1'][$index] . ",";
			$index++;
			$tracking_id++;
			echo $_POST['layer1'][$index];
			//echo("yay");
			}
		else
			$layer1string .= "0 ,";
		
		
	}
	$layer1string .= "},";
	//echo $tracking_id;
}
$layer1string .= "},";
*/

//echo $layer1string;
//echo $tracking_id;
/*
for ($i=0; $i<count($_POST['layer2']); $i++)
{
	echo("color_buffer2[");
	echo($_POST['layer2'][$i]);
	echo("] = color;");
	echo("<br />");
}
echo("send_colors(CS_LED2, color_buffer2);");
echo("<br /><br />");

for ($i=0; $i<count($_POST['layer3']); $i++)
{
	echo("color_buffer3[");
	echo($_POST['layer3'][$i]);
	echo("] = color;");
	echo("<br />");
}
echo("send_colors(CS_LED3, color_buffer3);");
echo("<br /><br />");

for ($i=0; $i<count($_POST['layer4']); $i++)
{
	echo("color_buffer4[");
	echo($_POST['layer4'][$i]);
	echo("] = color;");
	echo("<br />");
}
echo("send_colors(CS_LED4, color_buffer4);");
*/
?>
</body>
</html>