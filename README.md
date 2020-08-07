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

En Este caso ya que payload que nos esta mandando Helium esta codificado en base64, tenemos que decodificarlo en el NodeRED con el comando **atob()**, para mas informacion de este proceso.

Example:

    const encodedData = window.btoa('Hello, world'); // encode a string
    const decodedData = window.atob(encodedData); // decode the string

https://developer.mozilla.org/en-US/docs/Glossary/Base64

*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*

Story
AgroHelium
Sustainable platform of sensing and irrigation automation with predictive analysis via the Helium Network.

This will be the third iteration of two past projects;

The first one was Agrofox: https://www.hackster.io/107329/aggrofox-large-scale-and-urban-agriculture-iot-solution-8155fe

My intention is to test several platforms and to check which work best. (Spoiler: The Helium kit is at the top for the moment).

Introduction
In recent years Urban agriculture has made its mark in popular culture as an alternative to industrial farming. It offers several benefits and also helps to solve some of the most nefarious problems that we will have going forward regarding food supply, the growing population and the new trends favoring organic, naturally grown food. Despite all that it has been faced with a plethora of problems including its access to water, pollution concerns, and high maintenance costs. In addition to those most farming methods are very empirical in nature and it has been just a few years since the Internet of Things and other Industry 4.0 technologies have reached Agriculture. And among most of those, its degree of adoption is quite lackluster. Urban agriculture needs a cheap and readily available solution, for it to be sustainable.

Problem
IF we want to have the most impact with a project regarding sustainability, namely Water sustainability we have to focus on the industry that requires more of it, which is Agriculture.

And regarding that the main problem in agriculture is actually Water. Most countries have their periods of drought, but as years become even hotter because of climate change, drought greatly affects several parts.

So we get into a $22 Billion USD problem adding all the parameters. Industry 4.0 tools and automation are severely needed to attack this.

Here comes a new challenger!

After COVID-19 hit most industries were shown a loss in revenue of almost 30%. The pandemic is impacting global food systems, disrupting regional agricultural value chains, and posing risks to household food security.

Now we have to take much more seriously the fact that Urban Agriculture can provide us a "cushion" during all this problematic time.

Now, my personal problem:

This is a photo of one of the Tomato fruits I have in my backyard which I cannot continuously check. Sometimes I am away or very busy, and I tend to neglect its care. Another thing is regarding collecting fruit at the proper moments because they may become uneatable at some point. The problem regarding water can be taken care of if I automate irrigation and some more things.

Solution
Our solution to the problem will be to create a sustainable platform of sensing and irrigation automation with predictive analysis via the Helium devKit instead of relying entirely on cloud. With one objective in mind: SAVE WATER.

1.- Using temperature with humidity, soil moisture and soil temperature sensors, we will obtain sensor data every 6 min. LoRa technology has been chosen because the characteristics of long range and low power are excellent for remote areas and cities alike. For that in turn we will use the Helium devkit. Each batch of sensing is done at this frequency to send 120 packets per day to keep the LoRa flow going. The Helium Devkit is excellent to obtain the data from the sensors (using the vast array of libraries from Arduino) and send them directly to a cloud service via MQTT.

Then using the Openweathermap API and Node-RED we will create a Dashboard and notification capabilities.

2.- We will connect to our nearest Lora Gateway via the Helium network and send sensor data to AWS.

3.- Once we have the data at AWS, we will then send it to a Node-RED flow hosted on a Virtual machine or locally. We made it possible to develop almost any application with the obtained data. (All the applications are based on Node Red to make the prototyping easier). Examples of these applications:

Generate databases of our crops and their conditions.
Do data analysis to obtain predictive models in the long term.
Water automation systems with the data obtained (as we will do in this project).
Crop yield analysis.
3.1- We then will make a Dashboard with the data obtained for the complete and simple visualization of the data. For the application, we will perform data crossing with the OpenWeatherMap API, to perform the control of an electrovalve connected to another microcontroller. The data crossing obtained is used to check if that day is going to rain, and thus not use irrigation water in crops. Also if the system detects that water is needed, in the field by the humidity sensors, the irrigation system is turned on. In turn once a day an email will be sent to the farmer with the general information of his field or he can check anytime on his dashboard. Also everytime the irrigation system is online, a notification will be sent.

Why Helium Network?

One huge emphasis of this project is for it to also be used in Urban Agriculture and LoRa is the best choice for that one as we live in one of the biggest cities in the world (Mexico). And Sigfox which is perhaps your biggest competitor was found to be unreliable. I am eager to test this network. The only issue is perhaps that I will have to make my own gateway as there is no service in my country, but you already solved that problem with a tutorial on how to do that. And regarding scalability, LoRa is one of the best and easier neetworks to work it demanding low power and also performing as good as the components in your dvices and gateway are, for this application we can envision a manufacturing run of devices similar to this in every Urban Agriculture setting.

Step by step build up process:
1. Assemble the kit, circuits and connect the sensors
Take out your kit, get the shield on top of the board and connect it to your PC just to check if it blinks.



Now grab the following sensors:



And connect them to the board via some jumpers! But Use A0 and D7 to connect them to the board. Humidity, Air Temperature and a lot more variables are provided by the Shield from the kit making it much simpler than my past iterations.



No need for the GNSS module this time!

2. Valve Module:

Once the main circuit is completed, make the automated irrigation valve.

Bill of Materials:

Photon Particle (or any other Wifi board).
TIP120
12v Source.
Solenoid Valve Nc 1/2.
Diode 1N4007.
1 Resistances of 2.2kohm.
Cable, Solder, Jump wire or similar.
Real implementation:



Refrain from uploading both the Photon and Helium kit code at this moment, because we will need certain credentials.

2. Create your Node-Red Dashboard
Follow this guide here:

https://github.com/EddOliver/AgroJetson/tree/master/IBM%20cloud%20Agrojetson

That is a guide for the absolute beginner, but taking a look at our flow we can see several instances of what we are doing.

By using the MQTT node, we will sync it to AWS which our message broker for the internet of things, our two "things" have to be setup to this broker, but that part has to be manually done.

Go ahead and create a user on that platform or any other, you can also use Google IoT, IBM or Azure according to taste. At this point you will have to input your credentials into the Argon code. Just replace the proper information on the code.

Now we will go ahead and explain the configuration of the nodes which is very easy.

By taking both the "start" and "end" MQTT nodes we will form a messaging "bridge" so the Dashboard can "hear" the messages on Cloudmqtt. Grab the end node, go to server and then click on the edit icon to configure this part of the node.

Now input your credentials from the MQTT broker of your choice, here is done with Cloudmqtt.

Then grab the "start" node and set it up like so:

Notice the Topic, it is set up according to the topic of the sensor you will be using in this case the soil temperature sensor and is in accordance to the code on the Argon.

You'll have to do this three times (or whichever you need) if you are mannually creating the dashboard or just grab the code at the end and ONLY input into it your credentials.

3. Irrigation system via Openweathermap Forecast and Particle Photon.
We have to explain first the why's before the know how's.

The use of tracking the forecast of the weather is the main purpose of the project itself, that is to optimize water usage.

What use there is of having a sensor that tracks that the soil is dry and activate an irrigation system with that info, but it is going to rain that same day?

We can save a lot of water simply by using the weather forecast systems available to notify our platform that it is going to rain and stop from using water that day.

And of course we want to automate everything.

Without further ado:

1.- Get to: https://openweathermap.org/ and Sign up.

2.- After that then simply go to Sign In and click on API Keys, then copy the API KEY.

3.- Go then to your Node-RED flow. Remember the openweathermap node? Drag it to the Node-RED dashboard and configure it like so:

4.- Remember to paste an "Inject" node before, a "function" node after and also a "debug" node if you wish to check what has been transfered.

Double click the function node and paste the following code:

msg.payload= msg.payload[0].weather[0].main
msg.count = msg.payload
return msg;
What this does, is to seek the weather condition that we desire which is "Rain" and it puts it into the payload of the flow.

You can also grab a Text Dashboard node and connect it to this flow to get this info to the dashboard.

6.- Go to your particle IDE and paste the code for the Photon.

The main point of the code is understanding that it creates a function that can be accessed via the particle cloud. Whenever you input certain conditions to that functions externally you can do some previous programmed actions.

Flash it and go back to Node-RED. If you need aditional help with the Photon go directly to www.particle.io/start for a great place to begin.

7.- Now in Node-RED make a flow like so:

The Particle node is indeed the function node.

8.- Double click on the Particle node and click on the pencil on "Add new particle cloud". Then fill it like so:

Your access token is in your particle IDE, Devices section and clicking on the current device you are using. Update and in the next screen fill it with your device name that you can get on the Particle IDE and also on "CLoud Function" input "led".

9.- Now your Particle Photon node is configured to get an "on" or "off" payload and do the appropriate action with it.

10.- To configure properly the email node you have to log in to your gmail account and then go to: http://myaccount.google.com/u/1/lesssecureapps and turn it on, if you followed this guide accordingly, you set a password and username to your Node-RED so this procedure should be safe.

Then just fill the required fields.

11.- The most important step:

Finally, you have reached the end of this part of the tutorial so you have an idea of how to do the main parts of the project. Next is to do your own and use the concepts to get to a final product like the one presented here. There is also the main Flow that we did but we strongly suggest the reader to cultivate their own so you can have a great information harvest.

If you still want to have a complete solution in the "code section" there is the Node Red flow used in the project, which you should load into the Jetson Nano or any other computer (hint: that includes cloud services).

4. Going Green: Solar Power
This device has to have a solar panel to reduce the cost of infrastructure.

We recommend that you use at least a 2.5W Solar panel (I tried on a 2W panel and failed, it got very low power and lifetime) in tandem with a LiPo Battery like in the following circuit:

The power segment of the circuit is intended to power the circuit via a Solar Power during the day and then charge the LiPo battery so it can continue working at night.

For this purpose you can see the Regulator in the image that is a connection module that regulates the LiPo battery charge and the Solar Panel feeding energy to the system.

As previously stated I tried with my small 2W panel, but we are in the rainy season where I live so we need a bigger panel. I urge someone who already has the bigger panel to try it. For the Demo I will be using a Battery. BE very wary when trying this setup, I would go to battery just to be sure and by the way it will be an external one, because for it to work with the AA it may, you have to destroy a resistance.

Here are some reccomended links to these components:

Sunny Buddy: https://www.sparkfun.com/products/12885

Lipo Rider pro: https://www.seeedstudio.com/LiPo-Rider-Pro-p-992.html

Solar panel: https://www.seeedstudio.com/2-5W-Solar-Panel-116X160.html

LiPo Battery: https://www.adafruit.com/product/258

Now its time to upload the code into your dev board! (If you have already input your credentials properly beforehand, if not go to the next step). Get everything into their cases (3D CAD models provided).

At this point we have the two "Things" of our AIoT solution that sense and actuate.

5. Connect to Helium
First we need to create our account on the Helium console to get the previously needed credentials:

https://console.helium.com/

Go to the Devices tab to get the credentials. And create a Device to get them.

And save these values as they are your credentials!

Set up your Kit.

Follow the official guides to program it all with Arduino IDE!

https://developer.helium.com/devices/arduino-quickstart/st-discovery-lrwan1

Through Arduino's library manager Add the following libraries to Arduino IDE:

Now download the code for the kit provided at the bottom of this tutorial and input the credentials in the corresponding place:

Now let's check it it compiles:


Helium Console Check:

Once I had done the Setup on my board, I tried to send data to the Helium network, to my surprise I was able to correctly establish the connection to the network from a nearby Gateway in my city.

NOTE AND KUDOS!: Actually the Gateway was setup by one of my compadres developers. Victor (on Hackster:https://www.hackster.io/Altaga) completed his own gateway and he will have his documentation on everything including how to set up the miner on his Helium project's submision. I was in his vicinity while doing the project and he told me he was going to try and do a Gateway.

Check him out: https://www.hackster.io/Altaga/loradog-026fd7

The project would not have existed without that gateway.

The Gateway which gave me the connectivity to the Helium network had this name.

AWS IoT Setup Integration:
Thanks to the Helium Console and its AWS IoT integration guide, I was able to quickly setup as seen below.

https://developer.helium.com/console/integrations/awsiotcore

In this case, the Topic that I chose to send the data to AWS IoT was /GatewayAWS in the us-east-1 region.

Within AWS IoT we can see that every time we send a piece of information we obtain the following.

To connect AWS with NodeRED we must create the credentials in AWS IoT Core, we will go to the OnBoard section.

Then to get started.

Again to Get started.

We configure the credential for Linux and the Python Language.

We put whatever name we want, in my case I named it NodeRED.

We download the credential pack and give it Next Step.

We enter the NodeRED Thing since we must give our credential full permissions.

We enter the Security section and enter the Policy.

We edit the policy as shown on the screen to have full permissions.

In the settings section copy your Custom Endpoint since we will use it to configure NodeRED.

We will put our custom endpoint in the Server Name section and enter the TLS configuration.

We leave you in Github in the Cert folder the AWS CA Cert, the Certificate and the Private Key will be in the folder that we downloaded when creating the Thing.



6. Get some cases!
I took the time to make some cases for the project and the result is quite good as you can see:












Money Shots!



You can find the STLs at the bottom and in the project's Github!

Now we have everything setup and running let's do some testing.

Testing the Prototype:
Last video, here is how I installed the prototype in my Grove:

https://drive.google.com/drive/folders/1BQ2qmispSd6jcK3kSUhKNBIbHcz-rThv?usp=sharing

Benefits and Sustainability
As long as we can push initiatives like this forward we can get:

1. Reduction in Carbon emmisions The average meal has traveled 4,200 miles just to get to your table. Urban agriculture helps consumers reduce their “foodprint” by providing them the opportunity to purchase food that was grown within their community.

2. Creating Jobs These farms create opportunities to involve the community. Urban farms create jobs (and volunteer) opportunities in big cities, where poverty and hunger are often persistent issues.

3.- Stimulates your local economy which also builds the community around. An increase in small businesses stimulates local economy and supports the community by creating jobs right where people live.

4. Healthcare.- Bringing nutritious food to local communities has many direct health benefits, including reducing the risk of harmful conditions like heart disease, obesity, diabetes, and more.

5. Food quality.-These farms preserve biodiversity by cultivating heirloom varieties or those with lower shelf-stability. The proximity and connectedness to market allows for fresh, nutritious produce to become available to communities that have never had access to this in the past.

6. Green spaces: This contributes to the health of city ecosystems in a variety of ways. Greenery adds aesthetic appeal, reduces runoff from precipitation, provides restful spaces for the community, and counters the heat island effect by fixing carbon.

Commentary and Future Rollout
Sustainable disruption is needed because current methods are insufficient for the rising demand, infrastructure is costly and most fields are in remote areas. Also despite what it promises urban agriculture needs a cheap and readily available solution, for it to be sustainable. And COVID-19 just came to aggravate this situation even more.

The current project offers an initial solution to these problems by starting with one of my own, but it is not difficult to see how one of these can expand. This offers a cheap and affordable solution that can serve the local, home or urban farmer as it can automate several of their processes and most important of all provide valuable information about their crops that they can use to make good decisions.

Thinking about the future of the project, I think that Helium is a potent solution to this. We now have tried with WiFi boards, Cellular, Sigfox, but if we take into consideration the versatility of LoRa and the fact that the Helium Network also provides an incentive to feed the network, this is a much more robust solution. We have yet to try with a couple more technologies, but as a Blockchain aficionado, I think we have found our home with Helium.

References:

https://developer.helium.com/

https://www.freightfarms.com/blog/urban-farming-benefits

https://www.theecologycenter.org/10-ways-urban-farms-benefit-the-community/

https://www.vox.com/2016/5/15/11660304/urban-farming-benefits

https://www.hackster.io/107329/aggrofox-large-scale-and-urban-agriculture-iot-solution-8155fe





