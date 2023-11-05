#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");

static char* myname = "name";
static int myage = 21;
static int mybirthday[2] = {11, 27};
static int arr_argc = 0;

module_param(myname, charp, 0000);
//MODULE_PARM_DESC(myname, "A character string");
module_param(myage, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
//MODULE_PARA_DESC(myage, "An int");
module_param_array(mybirthday, int, &arr_argc, 0000);
//MODULE_PARA_DESC(mybirthday, "An array of int");

static int __init proc_init(void){
	pr_info("Hello, world\n");
	pr_info("my age is : %d\n", myage);
	pr_info("my name is : %s\n", myname);
	pr_info("my birthday is : %d/%d\n", mybirthday[0], mybirthday[1]);
	return 0;
}

static void __exit proc_exit(void){
	pr_info("Goodbye, world\n");	
}

module_init(proc_init);
module_exit(proc_exit);


			
			
