#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "touch.h"
#include <Serial.h>

#define I2C_SDA 2
#define I2C_SCL 3

uint8_t capa_addr = 0x55;

uint8_t SENSOR_EN[3] ={0x00,0xff,0xff};    
uint8_t TOGGLE_EN[2] ={0x04,0xff};      
uint8_t LED_ON_EN[2] ={0x06,0x00};
uint8_t SENSITIVITY0[2] ={0x08,0x03};
uint8_t SENSITIVITY1[2] ={0x09,0x03};
uint8_t SENSITIVITY2[2] ={0x0a,0x03};
uint8_t SENSITIVITY3[2] ={0x0b,0x03};  
uint8_t capa_I2C_ADDR[2] ={0x51,0x37};
uint8_t capb_I2C_ADDR[2] ={0x51,0x38};

void Touch_Setup()
    {
        gpio_set_function(I2C_SDA,GPIO_FUNC_I2C);
        gpio_set_function(I2C_SCL,GPIO_FUNC_I2C);

        gpio_pull_up(I2C_SCL);
        gpio_pull_up(I2C_SDA);
        Serial.println("Touch setup ok");

        _i2c_init(i2c0,400*1000);
        Serial.println("i2c setuping");
        Serial.println(i2c_write_blocking(i2c0,capa_addr,SENSOR_EN,sizeof(SENSOR_EN),false));
        i2c_write_blocking(i2c0,capa_addr,TOGGLE_EN,sizeof(TOGGLE_EN),false);Serial.print(".");
        i2c_write_blocking(i2c0,capa_addr,LED_ON_EN,sizeof(LED_ON_EN),false);Serial.print(".");
        i2c_write_blocking(i2c0,capa_addr,SENSITIVITY0,sizeof(SENSITIVITY0),false);Serial.print(".");
        i2c_write_blocking(i2c0,capa_addr,SENSITIVITY1,sizeof(SENSITIVITY1),false);Serial.print(".");
        i2c_write_blocking(i2c0,capa_addr,SENSITIVITY2,sizeof(SENSITIVITY2),false);Serial.print(".");
        i2c_write_blocking(i2c0,capa_addr,SENSITIVITY3,sizeof(SENSITIVITY3),false);Serial.print(".\n");
        Serial.println("i2c setup ok");
    }   
void init_capa()
    {
        uint8_t capaddress_reg[1] = {0x51};
        i2c_read_blocking(i2c0,0x37,capaddress_reg,8,false);
        Serial.println("I2C address was:"+ capaddress_reg[0]);
        i2c_write_blocking(i2c0,0x37,capb_I2C_ADDR,sizeof(capb_I2C_ADDR),false);
        i2c_read_blocking(i2c0,0x38,capaddress_reg,8,false);
        Serial.println("new I2C address is:"+ capaddress_reg[0]);
    }