I2C
===

I2C  modules  in linux

platform driver
=======================
 /drivers/i2c/bussed/i2c-s3c2410.c ����һ��platform����
static struct platform_driver s3c24xx_i2c_driver = {
	.probe		= s3c24xx_i2c_probe,
	.remove		= s3c24xx_i2c_remove,
	.id_table	= s3c24xx_driver_ids,
	.driver		= {
		.owner	= THIS_MODULE,
		.name	= "s3c-i2c",
		.pm	= S3C24XX_DEV_PM_OPS,
	},
};

i2c��������Դ�����
i2c_adap_s3c_init()
	platform_driver_register(drv)
		drv->driver.bus = &platform_bus_type;  �豸����������ƽ̨������  
		driver_register(&drv->driver);		   ע���豸����
			bus_add_driver(&drv->driver)
				struct driver_private *priv;
				priv->driver = drv;
				drv->p = priv;
				priv->kobj.kset = bus->p->drivers_kset;
				error = kobject_init_and_add(&priv->kobj, &driver_ktype, NULL,
				     "%s", drv->name);
				driver_attach(drv);
				     bus_for_each_dev(drv->bus, NULL, drv, __driver_attach);
				     	 __driver_attach(struct device *dev, void *data)
				     	 	if (!driver_match_device(drv, dev))
								return 0;
							if (!dev->driver)
								driver_probe_device(drv, dev);
									really_probe(dev, drv)		
ƽ̨�豸��ע�᣺
MODULE_DEVICE_TABLE(platform, s3c24xx_driver_ids);
				     
����ƽ̨���ߵ�ע�᣺
��㣺Main.c
	kernel_init()
		do_basic_setup()
			driver_init()
				platform_bus_init()
					error = device_register(&platform_bus);
					if (error)
						return error;
					error =  bus_register(&platform_bus_type);