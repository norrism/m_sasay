#m_sasay - InspIRCd Module

Description
-

m_sasay is a third party InspIRCd module that allows opers to send messages as other users to a channel.

Installation
-

1. Download the file m_sasay.cpp and place it in the '/src/modules/' directory of your InspIRCd installation.

2. Add the following code to your 'modules.conf' file

        #-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#
        # SASAY module: Adds the /SASAY command which sends a message from any
        # user to a channel.
        # This module is oper-only.
        # To use, SASAY must be in one of your oper class blocks.
        <module name="m_sasay.so">

3. Modify your 'opers.conf' file to include 'SASAY' as a command under the SACommands oper class. e.g:

        <class name="SACommands" commands="SAJOIN SAPART SANICK SAQUIT SATOPIC SAKICK SAMODE OJOIN SASAY">

4. Run the following command from the root InspIRCd directory:


        make && make install
    
    
5. Start the InspIRCd server.

Usage
-

You must be identified as an oper with SASAY command privledges to use this. The following command would send \<message> to \<channel> from \<nick>.

    /SASAY <nick> <channel> <message>
