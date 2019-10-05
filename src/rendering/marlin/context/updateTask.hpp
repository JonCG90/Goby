//
//  updateTask.hpp
//  Goby
//
//  Created by Jonathan Graham on 10/5/19.
//

#ifndef MARLIN_UPDATETASK_HPP
#define MARLIN_UPDATETASK_HPP

#include <iostream>

namespace marlin
{

class Context;

class UpdateTask
{
public:
    
    UpdateTask( Context &i_context, std::function< void( Context& i_context ) > i_task );
    virtual ~UpdateTask() = default;
    
    void execute( Context &i_context );
    
protected:
    
    Context* m_context;
    std::function< void( Context& i_context ) > m_task;
};

using UpdateTaskPtr = std::shared_ptr< UpdateTask >;
    
} // namespace marlin

#endif /* MARLIN_UPDATETASK_HPP */
