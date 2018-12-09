#pragma once

namespace GDS
{

class LibElement;
typedef std::shared_ptr<LibElement> LibElementPtr;

class LibElement
{
public:
	LibElement(const std::string &name, const std::string &comment,
		const std::vector<uint8_t>& icon,
		const LibElementPtr &parent = LibElementPtr(nullptr));
	~LibElement();

	const std::string& getName() const;
	const std::string& getComment() const;
	const std::vector<uint8_t>& getIcon() const;
	const LibElementPtr& getParent() const;

private:
	std::string name_;
	std::string comment_;
	std::vector<uint8_t> icon_;
	LibElementPtr parent_;
};

} // namespace GDS
