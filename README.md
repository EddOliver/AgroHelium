# AgroHelium
Sustainable platform of sensing and irrigation automation with predictive analysis via the Helium Network.

Para conectar AWS con NodeRED debemos crear las credenciales en AWS IoT Core, iremos a la seccion de OnBoard.

<img src="https://i.ibb.co/gMLkgkR/aws1.png" width="1000">

Nos vamos a la seccion de Get started

<img src="https://i.ibb.co/Y8jKFCC/aws2.png" width="1000">

Una vez mas presionamos Get started

<img src="https://i.ibb.co/khQz5Db/aws3.png" width="1000">

Configuramos la credecial para linux y lenguaje python.

<img src="https://i.ibb.co/JqsgKKz/aws4.png" width="1000">

Le ponemos el nombre que querramos, en mi caso le puse NodeRED.

<img src="https://i.ibb.co/8KbLV39/aws5.png" width="1000">

Descargamos el pack de credenciales y le damos Next Step.

<img src="https://i.ibb.co/rwX7zj5/aws6.png" width="1000">

Entramos en el Thing de NodeRED ya que debemos darle a nuestra credencial permisos completos.

<img src="https://i.ibb.co/3R4dhmj/aws7.png" width="1000">

Entramos en la seccion de Security y entramos en la Policy.

<img src="https://i.ibb.co/Kb4Km4S/aws8.png" width="1000">

Editamos la policy como se muestra en la pantalla para tener permisos completos.

<img src="https://i.ibb.co/ThLdG5T/aws9.png" width="1000">

En la seccion de settings copia tu Custom Endpoint ya que lo usaremos para configurar NodeRED.

<img src="https://i.ibb.co/JqFFKhD/aws9-5.png" width="1000">

Pondremos nuestro custom endpoint en la seccion de Server Name y entraremos la configuracion de TLS.

<img src="https://i.ibb.co/1ZmvSj2/aws10.png" width="1000">

Te dejamos en Github en la carpeta de Cert el CA Cert de AWS, el Certificate y el Private Key estaran en la carpeta que descargamos al crear la Thing

<img src="https://i.ibb.co/31wqNPn/aws11.png" width="1000">



