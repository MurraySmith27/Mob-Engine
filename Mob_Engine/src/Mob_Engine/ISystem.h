
class ISystem {
public:
	virtual void Start() = 0;

	virtual void FrameUpdate() = 0;

	virtual void AddComponent() = 0;

};