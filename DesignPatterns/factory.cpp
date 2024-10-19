#include <cstddef>
#include <iostream>

class IRenderer {
    public:
    virtual bool LoadScene(const std::string& fileName) = 0;
    virtual void SetViewPort(int w, int h) = 0;
    virtual void Render() = 0;
};

enum Renderer {
    OPENGL = 0,
    DIRECTX,
    MESA
};

class OpenGLRenderer : public IRenderer {
    private:
    std::string name;

    public:
    OpenGLRenderer(const std::string& renderer_name) : name(renderer_name) {}

    bool LoadScene(const std::string& fileName) override {
        std::cout << name << " Loading Scene from file: " << fileName << "\n";
        return true;
    }
    void SetViewPort(int w, int h) override {
        std::cout << "Setting Viewport width: " << w << " height: " << h << " from " << name << std::endl;
    }
    void Render() override {
        std::cout << "Rendering.... using " << name << " renderer" << std::endl;
    }
};

class DirectX : public IRenderer {
    private:
    std::string name;

    public:
    DirectX(const std::string& renderer_name) : name(renderer_name) {}

    bool LoadScene(const std::string& fileName) override {
        std::cout << name << " Loading Scene from file: " << fileName << "\n";
        return true;
    }
    void SetViewPort(int w, int h) override {
        std::cout << "Setting Viewport width: " << w << " height: " << h << " from " << name << std::endl;
    }
    void Render() override {
        std::cout << "Rendering.... using " << name << " renderer" << std::endl;
    }
};

class MesaRenderer : public IRenderer {
    private:
    std::string name;

    public:
    MesaRenderer(const std::string& renderer_name) : name(renderer_name) {}

    bool LoadScene(const std::string& fileName) override {
        std::cout << name << " Loading Scene from file: " << fileName << "\n";
        return true;
    }
    void SetViewPort(int w, int h) override {
        std::cout << "Setting Viewport width: " << w << " height: " << h << " from " << name << std::endl;
    }
    void Render() override {
        std::cout << "Rendering.... using " << name << " renderer" << std::endl;
    }
};

class RenderFactory {
    public:
    IRenderer *CreateRender(Renderer);
};

/**
 * CreateRender is a factory method that takes an enum value of type Renderer and
 * returns a pointer to an object that implements the IRenderer interface.
 *
 * The method uses a switch statement to determine which type of IRenderer object
 * to create, based on the value of the Renderer enum that is passed in.  The
 * switch statement is used to dispatch to the correct constructor based on the
 * value of the Renderer enum.
 *
 * The method returns a pointer to an IRenderer object.  If the value of the
 * Renderer enum is not recognized, the method returns a nullptr.
 */
IRenderer *RenderFactory::CreateRender(Renderer renderer)
{
    /**
     * The switch statement is used to dispatch to the correct constructor
     * based on the value of the Renderer enum.
     */
    switch (renderer)
    {
        /**
         * If the value of the Renderer enum is Renderer::OPENGL, then create
         * an OpenGLRenderer object and return a pointer to it.
         */
        case Renderer::OPENGL:
            return new OpenGLRenderer("OpenGL");
            break;

        /**
         * If the value of the Renderer enum is Renderer::DIRECTX, then create
         * a DirectX object and return a pointer to it.
         */
        case Renderer::DIRECTX:
            return new DirectX("DirectX");
            break;

        /**
         * If the value of the Renderer enum is Renderer::MESA, then create a
         * MesaRenderer object and return a pointer to it.
         */
        case Renderer::MESA:
            return new MesaRenderer("Mesa");
            break;

        /**
         * If the value of the Renderer enum is not recognized, then return a
         * nullptr.
         */
        default:
            return nullptr;
    }
}


int main(){
    RenderFactory renderFactory;
    IRenderer *renderer1 = renderFactory.CreateRender(Renderer::MESA);
    renderer1->LoadScene("scene.bin");
    renderer1->SetViewPort(100, 100);
    renderer1->Render();

    std::cout << std::endl;

    IRenderer *renderer2 = renderFactory.CreateRender(Renderer::OPENGL);
    renderer2->LoadScene("scene.bin");
    renderer2->SetViewPort(100, 100);
    renderer2->Render();

    return 0;
}