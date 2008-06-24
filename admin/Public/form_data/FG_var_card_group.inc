<?php


getpost_ifset(array('id', 'name', 'id_agi_conf'));


$HD_Form = new FormHandler("cc_card_group","Card Group");

$HD_Form -> FG_DEBUG = 0;


$HD_Form -> AddViewElement(gettext("NAME"), "name", "25%", "center", "sort");
$HD_Form -> AddViewElement(gettext("AGI CONF"), "id_agi_conf", "25%", "center", "sort");
$HD_Form -> FieldViewElement ( 'name, id_agi_conf');


$HD_Form -> CV_NO_FIELDS  = gettext("NO CARD GROUP CREATED!"); 
$HD_Form -> CV_DISPLAY_LINE_TITLE_ABOVE_TABLE = false;
$HD_Form -> CV_TEXT_TITLE_ABOVE_TABLE = '';
$HD_Form -> CV_DISPLAY_FILTER_ABOVE_TABLE = false;
$HD_Form -> FG_VIEW_TABLE_WITDH = '70%';


$DBHandle  = DbConnect();
$conf_table = new Table("cc_config_group", "group_title");
$clause_conf_agi = "cc_config_group.group_title LIKE 'agi_conf_%'";
$result_config= $conf_table -> Get_list ($DBHandle, $clause_conf_agi, null, null, null, null, null, null);
$agi_list = array();
$i=1;
$agi_list["0"] = array( gettext("NOT DEFINED"), "-1");
foreach ($result_config as $value){
$agi_list[i] = array($value["group_title"], substr($value["group_title"],8));	
$i++;
}


$HD_Form -> FG_EDITION = true;
$HD_Form -> FG_DELETION = true;


$HD_Form -> AddEditElement ( gettext("NAME"),	
		"name",	'$value',	
		"INPUT",
		"size= maxlength=40",
		"0",
		gettext("Insert the provider name"), 
		"" , "", "",	"", "", "", "", "" );
$HD_Form -> AddEditElement (gettext("AGI CONF"),
	"id_agi_conf",
	'$value',
	"SELECT",
	"",
	"",
	"",
	"list" , "", "", "", $agi_list, "%1", "", "");

$HD_Form -> FieldEditElement ('name, id_agi_conf');





$HD_Form -> FG_INTRO_TEXT_EDITION= gettext("You can modify, through the following form, the different properties of your")." ".$HD_Form->FG_INSTANCE_NAME;
$HD_Form -> FG_INTRO_TEXT_ASK_DELETION = gettext("If you really want remove this")." ".$HD_Form->FG_INSTANCE_NAME.", ".gettext("click on the delete button.");
$HD_Form -> FG_INTRO_TEXT_ADD = gettext("you can add easily a new")." ".$HD_Form->FG_INSTANCE_NAME.".<br>".gettext("Fill the following fields and confirm by clicking on the button add.");


$HD_Form -> FG_INTRO_TEXT_ADITION = gettext("Add $HD_Form->FG_INSTANCE_NAME.");
$HD_Form -> FG_TEXT_ADITION_CONFIRMATION = gettext("Your new")." ".$HD_Form->FG_INSTANCE_NAME." ".gettext("has been inserted.")."<br>";


$HD_Form -> FG_BUTTON_EDITION_SRC = $HD_Form -> FG_BUTTON_ADITION_SRC  = Images_Path . "/cormfirmboton.gif";
$HD_Form -> FG_BUTTON_EDITION_BOTTOM_TEXT = $HD_Form -> FG_BUTTON_ADITION_BOTTOM_TEXT = gettext("Click 'Confirm Data' to continue");



$HD_Form -> FG_GO_LINK_AFTER_ACTION_ADD = $_SERVER['PHP_SELF']."?atmenu=document&stitle=Document&wh=AC&id=";
$HD_Form -> FG_GO_LINK_AFTER_ACTION_EDIT = $_SERVER['PHP_SELF']."?atmenu=document&stitle=Document&wh=AC&id=";
$HD_Form -> FG_GO_LINK_AFTER_ACTION_DELETE = $_SERVER['PHP_SELF']."?atmenu=document&stitle=Document&wh=AC&id=";
?>