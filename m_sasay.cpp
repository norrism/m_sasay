 /*
 * m_sasay -- InspIRCd Module
 *
 *   Copyright (C) 2015 Michael Norris
 * 
 * This file contains a third party module for InspIRCd.  You can
 * redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, version 2.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "inspircd.h"

/* $ModDesc: Provides command SASAY which allows opers to send messages as other users to a channel */

/** Handle /SASAY
 */
class CommandSasay : public Command
{
 public:
	CommandSasay(Module* Creator) : Command(Creator,"SASAY", 3, 3)
	{
		allow_empty_last_param = false;
		flags_needed = 'o'; Penalty = 0; syntax = "<nick> <channel> <message>";
	}

	CmdResult Handle (const std::vector<std::string>& parameters, User *user)
	{
		
		User* target = ServerInstance->FindNick(parameters[0]);
		Channel* channel = ServerInstance->FindChan(parameters[1]);
		std::string message = parameters[2];
		
		if ((target) && (target->registered == REG_ALL) && (channel))
		{
		
			if(!channel->HasUser(target))
			{
				user->WriteServ("NOTICE %s :*** %s is not on the channel %s", user->nick.c_str(), target->nick.c_str(), channel->name.c_str());
				return CMD_FAILURE;
			}
				
			channel->WriteChannel(target, "PRIVMSG %s :%s", channel->name.c_str(), message.c_str());
			ServerInstance->SNO->WriteGlobalSno('a', user->nick + " used SASAY to make " + target->nick.c_str() + " say in " + channel->name.c_str() + ": \"" + message + "\"");
			
			return CMD_SUCCESS;
		}
		else
		{
			user->WriteServ("NOTICE %s :*** Invalid nickname or channel", user->nick.c_str());
		}
		return CMD_FAILURE;
	}
};

class ModuleSasay : public Module
{
	CommandSasay cmd;
	
 public:
	ModuleSasay() 
		: cmd(this)
	{
	}
	
	void init()
	{
		ServerInstance->Modules->AddService(cmd);
	}

	Version GetVersion()
	{
		return Version("Provides command SASAY which allows opers to send messages as other users to a channel", VF_NONE);
	}
};

MODULE_INIT(ModuleSasay)
