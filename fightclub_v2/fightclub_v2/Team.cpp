#include "Team.h"

bool Team::GetAlive() const
{
    return m_members[0].GetAlive() && m_members[1].GetAlive();
}
