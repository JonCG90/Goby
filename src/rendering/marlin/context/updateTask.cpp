//
//  updateTask.cpp
//  Goby
//
//  Created by Jonathan Graham on 10/5/19.
//

#include "updateTask.hpp"

#include <marlin/context/context.hpp>

namespace marlin
{

UpdateTask::UpdateTask( Context &i_context, std::function< void( Context& i_context ) > i_task )
{
    m_task = i_task;
    m_context = &i_context;
}

void UpdateTask::execute( Context &i_context )
{
    m_task( i_context );
}
    
} // namespace marlin

