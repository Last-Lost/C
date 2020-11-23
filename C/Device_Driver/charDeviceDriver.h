/* Global definition for the example character device driver */

int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

#define SUCCESS 0
#define DEVICE_NAME "opsysmem"	// Dev name as it appears in /proc/devices   */
#define BUF_LEN (6*1024)		// Max length of the message from the device */

/* 
 * Global variables are declared as static, so are global within the file. 
 */

struct cdev *my_cdev;
       dev_t dev_num;

static int Major;
static int Device_Open = 0;
static int count_bytes = 0;	             

struct List {

	char data[BUF_LEN];
	struct List *next;

};

typedef struct List List;
static List *root = NULL;
static List *found_node = NULL;

static struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};
