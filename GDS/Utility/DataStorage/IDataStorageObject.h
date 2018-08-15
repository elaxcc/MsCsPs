#pragma once

namespace GDS
{

namespace DataStorage
{

class IDataStorageObject
{
public:
	IDataStorageObject(const std::string& name);
	virtual ~IDataStorageObject();
	
	void set_name(const std::string& name);
	const std::string& get_name() const;

	virtual unsigned get_data_size() const = 0;
	virtual std::vector<unsigned char> serialize() = 0;

private:
	std::string name_;
};
typedef std::shared_ptr<IDataStorageObject> IDataStorageObjectPtr;

} // namespace DataStorage

} // namespace GDS

