











#include "StateManager.h"

StateManager::StateManager()
    : m_add(false), m_replace(false), m_remove(false), m_removeAll(false) {
}

StateManager::~StateManager() {
   
    while (!m_stateStack.empty()) {
        m_stateStack.top()->OnExit();
        m_stateStack.pop();
    }
}

void StateManager::Add(std::unique_ptr<State> toAdd, bool replace) {
    m_add = true;
    m_newState = std::move(toAdd);
    m_replace = replace;
}

void StateManager::PopCurrent() {
    m_remove = true;
}

void StateManager::PopAll() {
    m_removeAll = true;
    m_remove = false;
}

void StateManager::PauseCurrent() {
    if (!m_stateStack.empty()) {
        m_pausedState = std::move(m_stateStack.top());
        m_stateStack.pop();
        m_pausedState->OnPause();

        if (!m_stateStack.empty()) {
            m_stateStack.top()->OnResume();
        }
    }
}

void StateManager::ResumePaused() {
    if (m_pausedState) {
        if (!m_stateStack.empty()) {
            m_stateStack.top()->OnPause();
        }

        m_stateStack.push(std::move(m_pausedState));
        m_stateStack.top()->OnResume();
    }
}

void StateManager::ProcessStateChanges() {
    
    if (m_removeAll) {
        while (!m_stateStack.empty()) {
            m_stateStack.top()->OnExit();
            m_stateStack.pop();
        }
        m_removeAll = false;
    }
    
    else if (m_remove && !m_stateStack.empty()) {
        m_stateStack.top()->OnExit();
        m_stateStack.pop();

        if (!m_stateStack.empty()) {
            m_stateStack.top()->OnResume();
        }
        m_remove = false;
    }

    
    if (m_add) {
        
        if (m_replace && !m_stateStack.empty()) {
            m_stateStack.top()->OnExit();
            m_stateStack.pop();
            m_replace = false;
        }

       
        if (!m_stateStack.empty()) {
            m_stateStack.top()->OnPause();
        }

        
        m_stateStack.push(std::move(m_newState));
        m_stateStack.top()->OnEnter();
        m_add = false;
    }
}

std::unique_ptr<State>& StateManager::GetCurrent() {
    return m_stateStack.top();
}

bool StateManager::IsEmpty() const {
    return m_stateStack.empty();
}